package material;
import java.util.HashMap;
import java.util.Map;
import java.util.Iterator;
import java.util.Set;
//购物车类
public class Cart {
	//购买商品的集合
	private HashMap<Goods,Integer> goods;//HashMap<key,value>，此处的key是一个Goods对象，value用来记录相应good的数量
	//购物车的总金额
	private double totalPrice;
	//构造方法
	public Cart()
	{
		goods = new HashMap<Goods,Integer>();
		totalPrice = 0.0;
	}
	public HashMap<Goods,Integer> getGoods(){
		return goods;
	}
	public double getTotalPrice() {
		return totalPrice;
	}
	public void setTotalPrice(double totalPrice) {
		this.totalPrice = totalPrice;
	}
	public void setGoods(HashMap<Goods, Integer> goods) {
		this.goods = goods;
	}
	//添加商品进购物车的方法
	public boolean addGoodsInCart(Goods item,int number){
		if(goods.containsKey(item)){
			goods.put(item, goods.get(item )+number);
		}else{	
			goods.put(item, number);
		}
		calTotalPrice();	//重新计算购物车总金额
		return true;
	}
	public double calTotalPrice(){
		double sum=0.0;
		Set<Goods>keys = goods.keySet();//获得键的集合
		Iterator<Goods> it = keys.iterator();//获得迭代器对象
		while(it.hasNext()){
			Goods i = it.next();
			sum+=i.getPrice()*goods.get(i);//求和price*number
		}
		this.setTotalPrice(sum);
		return this.getTotalPrice();
	}
	//删除商品的方法
	public boolean delGoods(Goods item){
		goods.remove(item);
		calTotalPrice();	//重新计算购物车总金额
		return true;
	}
}
