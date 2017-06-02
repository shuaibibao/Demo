package servlet;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import dao.GoodDao;
import material.Cart;
import material.Goods;

//��Ӧ��cart��servlet
@WebServlet("/CartServlet")
public class CartServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	//��ʾ���ﳵ�Ķ��� ,add,show,delete
	private String action ;
	//��Ʒҵ���߼���Ķ���
	private GoodDao idao = new GoodDao();
    
    public CartServlet() {
        super();
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		response.setContentType("text/html;charset=utf-8");
		PrintWriter out = response.getWriter();
		if(request.getParameter("action")!=null)
		{
			this.action = request.getParameter("action");
			if(action.equals("add")) //����������Ʒ�����ﳵ
			{
				if(addToCart(request,response))
				{
					request.getRequestDispatcher("success.jsp").forward(request, response);
				}
				else
				{
					request.getRequestDispatcher("failed.jsp").forward(request, response);
				}
			}
			if(action.equals("show"))//�������ʾ���ﳵ
			{	
				request.getRequestDispatcher("MyCart.jsp").forward(request, response);
			}
			if(action.equals("del")) //�����ִ��ɾ�����ﳵ�е���Ʒ
			{
				
				if(deleteFromCart(request,response))
				{
					request.getRequestDispatcher("MyCart.jsp").forward(request, response);
					
				}
				else
				{
					out.println("error");
				}
			}
		}
	}
	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		doGet(request, response);
	}
	//�����Ʒ�����ﳵ�ķ���
		private boolean addToCart(HttpServletRequest request, HttpServletResponse response)
		{   
			String id = request.getParameter("id");
			String number=null;
			number=request.getParameter("num");
			Goods item = idao.findById(Integer.parseInt(id));
			//�Ƿ��ǵ�һ�θ����ﳵ�����Ʒ,��Ҫ��session�д���һ���µĹ��ﳵ����
			if(request.getSession().getAttribute("cart")==null)
			{
				Cart cart = new Cart();
				request.getSession().setAttribute("cart",cart);
			}
			//��session��ȡ��cart�������ﳵ������µ���Ʒ
			Cart cart = (Cart)request.getSession().getAttribute("cart");
			
			if(cart.addGoodsInCart(item,Integer.parseInt(number)))
			{
				//System.out.println("=====����addtocart3====================="+number+"--------");
				return true;
			}
			else
			{
				return false;
			}

		}
		
		//�ӹ��ﳵ��ɾ����Ʒ
		private boolean deleteFromCart(HttpServletRequest request, HttpServletResponse response)
		{
			String id = request.getParameter("id");
			Cart cart = (Cart)request.getSession().getAttribute("cart");
		    Goods item = idao.findById(Integer.parseInt(id));
		    if(cart.delGoods(item))
		    {
		    	return true;
		    }
		    else
		    {
		    	return false;
		    }
		}
}
	
