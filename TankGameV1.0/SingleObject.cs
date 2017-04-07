using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TankGameV1._0
{
    //这个单例设计模式为我们生成全局唯一的一个游戏对象
    class SingleObject
    {
        private SingleObject() { }

        public static SingleObject _singleobeject=null;

        public static SingleObject getSingle()
        {
            if (_singleobeject == null)
                _singleobeject = new SingleObject();
            return _singleobeject;
        }

        public PlayerTank pt
        {
            get;
            set;
        }

        List<EnemyZD> listEnemyZD=new List<EnemyZD>();//注意这样的写法
        List<PlayerZD> listPlayerZD=new List<PlayerZD>();
        List<EnemyTank> listEnemyTank = new List<EnemyTank>();
        List<Boom> listBoom = new List<Boom>();

        public void addGameObject(GameObject go)//实现多态
        {
            if (go is PlayerTank)
                pt = go as PlayerTank;
            else if (go is EnemyZD)
                listEnemyZD.Add(go as EnemyZD);
            else if (go is PlayerZD)
                listPlayerZD.Add(go as PlayerZD);
            else if (go is EnemyTank)
                listEnemyTank.Add(go as EnemyTank);
            else if (go is Boom)
            {
                listBoom.Add(go as Boom);
            }
        }

        public void removeGameObject(GameObject go)
        {
            if (go is Boom)
            {
                listBoom.Remove(go as Boom);
            }
            if (go is PlayerZD)
            {
                listPlayerZD.Remove(go as PlayerZD);
            }
            if (go is EnemyZD)
            {
                listEnemyZD.Remove(go as EnemyZD);
            }
            if (go is EnemyTank)
            {
                listEnemyTank.Remove(go as EnemyTank);
            }
        }

        public void draw(Graphics g)
        {
            pt.draw(g);
            for (int i = 0; i < listEnemyZD.Count; i++)
            {
                listEnemyZD[i].draw(g);
            }
            for (int i = 0; i < listPlayerZD.Count; i++)
            {
                listPlayerZD[i].draw(g);
            }
            for (int i = 0; i < listEnemyTank.Count; i++)
            {
                listEnemyTank[i].draw(g);
            }
            for (int i = 0; i < listBoom.Count; i++)
            {
                listBoom[i].draw(g);
            }
        }

        public void PZJC()
        {
            #region 首先来判断玩家的子弹是否打在了敌人的身上
            for (int i = 0; i < listPlayerZD.Count; i++)
            {
                for (int j = 0; j < listEnemyTank.Count; j++)
                {

                    if (listPlayerZD[i].getRectangle().IntersectsWith(listEnemyTank[j].getRectangle()))//使用IntersectsWith()函数来进行碰撞检测
                    {
                        //表示玩家的子弹打到了敌人的身上
                        //敌人应该减少生命值
                        listEnemyTank[j].life -= listPlayerZD[i].power;
                        listEnemyTank[j].IsOver();
                        break;
                    }
                }
            }
            #endregion
        }
    }
}
