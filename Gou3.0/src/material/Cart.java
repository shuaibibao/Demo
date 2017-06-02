package material;
import java.util.HashMap;
import java.util.Map;
import java.util.Iterator;
import java.util.Set;
//���ﳵ��
public class Cart {
	//������Ʒ�ļ���
	private HashMap<Goods,Integer> goods;//HashMap<key,value>���˴���key��һ��Goods����value������¼��Ӧgood������
	//���ﳵ���ܽ��
	private double totalPrice;
	//���췽��
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
	//�����Ʒ�����ﳵ�ķ���
	public boolean addGoodsInCart(Goods item,int number){
		if(goods.containsKey(item)){
			goods.put(item, goods.get(item )+number);
		}else{	
			goods.put(item, number);
		}
		calTotalPrice();	//���¼��㹺�ﳵ�ܽ��
		return true;
	}
	public double calTotalPrice(){
		double sum=0.0;
		Set<Goods>keys = goods.keySet();//��ü��ļ���
		Iterator<Goods> it = keys.iterator();//��õ���������
		while(it.hasNext()){
			Goods i = it.next();
			sum+=i.getPrice()*goods.get(i);//���price*number
		}
		this.setTotalPrice(sum);
		return this.getTotalPrice();
	}
	//ɾ����Ʒ�ķ���
	public boolean delGoods(Goods item){
		goods.remove(item);
		calTotalPrice();	//���¼��㹺�ﳵ�ܽ��
		return true;
	}
}
