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

//对应于cart的servlet
@WebServlet("/CartServlet")
public class CartServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	//表示购物车的动作 ,add,show,delete
	private String action ;
	//商品业务逻辑类的对象
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
			if(action.equals("add")) //如果是添加商品进购物车
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
			if(action.equals("show"))//如果是显示购物车
			{	
				request.getRequestDispatcher("MyCart.jsp").forward(request, response);
			}
			if(action.equals("del")) //如果是执行删除购物车中的商品
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
	//添加商品进购物车的方法
		private boolean addToCart(HttpServletRequest request, HttpServletResponse response)
		{   
			String id = request.getParameter("id");
			String number=null;
			number=request.getParameter("num");
			Goods item = idao.findById(Integer.parseInt(id));
			//是否是第一次给购物车添加商品,需要给session中创建一个新的购物车对象
			if(request.getSession().getAttribute("cart")==null)
			{
				Cart cart = new Cart();
				request.getSession().setAttribute("cart",cart);
			}
			//从session中取出cart，往购物车里加入新的商品
			Cart cart = (Cart)request.getSession().getAttribute("cart");
			
			if(cart.addGoodsInCart(item,Integer.parseInt(number)))
			{
				//System.out.println("=====进入addtocart3====================="+number+"--------");
				return true;
			}
			else
			{
				return false;
			}

		}
		
		//从购物车中删除商品
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
	
