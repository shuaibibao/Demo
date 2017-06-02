using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Media;
using System.Text;
using System.Threading.Tasks;
using TankGameV1._0.Properties;

namespace TankGameV1._0
{
    //这个单例设计模式为我们生成全局唯一的一个游戏对象
    class SingleObject
    {
        private SingleObject() { }

        public static SingleObject _singleobeject = null;

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

        List<EnemyZD> listEnemyZD = new List<EnemyZD>();//注意这样的写法
        List<PlayerZD> listPlayerZD = new List<PlayerZD>();
        List<EnemyTank> listEnemyTank = new List<EnemyTank>();
        List<Boom> listBoom = new List<Boom>();
        List<TankBorn> listTankBorn = new List<TankBorn>();
        List<ZhuangBei> listZhuangBei = new List<ZhuangBei>();
        List<Wall> listWall = new List<Wall>();

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
            else if (go is TankBorn)
            {
                listTankBorn.Add(go as TankBorn);
            }
            else if (go is ZhuangBei)
            {
                listZhuangBei.Add(go as ZhuangBei);
            }
            else if (go is Wall )
            {
                listWall.Add(go as Wall);
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
            if (go is TankBorn)
            {
                listTankBorn.Remove(go as TankBorn);
            }
            if (go is ZhuangBei)
            {
                listZhuangBei.Remove(go as ZhuangBei);
            }
            if (go is Wall)
            {
                listWall.Remove(go as Wall);
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
            for (int i = 0; i < listTankBorn.Count; i++)
            {
                listTankBorn[i].draw(g);
            }
            for (int i = 0; i < listZhuangBei.Count; i++)
            {
                listZhuangBei[i].draw(g);
            }
            for (int i = 0; i < listWall.Count; i++)
            {
                listWall[i].draw(g);
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
                        //并且移除玩家子弹
                        listPlayerZD.Remove(listPlayerZD[i]);
                        break;
                    }
                }
            }
            #endregion

            #region 判断敌人的子弹是否搭载玩家坦克上
            for (int i = 0; i < listEnemyZD.Count; i++)
            {
                if (listEnemyZD[i].getRectangle().IntersectsWith(pt.getRectangle()))//使用IntersectsWith()函数来进行碰撞检测
                {

                    pt.life -= listEnemyZD[i].power;
                    pt.IsOver();
                    //并且移除玩家子弹
                    listEnemyZD.Remove(listEnemyZD[i]);
                    break;
                }
            }
                #endregion 玩家是否和产生的装备发生了碰撞

            #region 判断玩家是否吃到装备
            for (int i = 0; i < listZhuangBei.Count; i++)
            {
                //玩家吃到了装备
                if (listZhuangBei[i].getRectangle().IntersectsWith(pt.getRectangle()))
                {
                    //调用JudgeZB
                    JudgeZB(listZhuangBei[i].ZBType);
                    //玩家吃到了装备后 应该将装备移除
                    listZhuangBei.Remove(listZhuangBei[i]);
                    //添加吃了装备的声音
                    SoundPlayer sp = new SoundPlayer(Resources.add);
                    sp.Play();
                }
            }
            #endregion

            #region 判断玩家子弹是否与玩家坦克碰撞
            for (int i = 0; i < listPlayerZD.Count; i++)
            {
                for (int j = 0; j < listWall.Count; j++)
                {

                    if (listPlayerZD[i].getRectangle().IntersectsWith(listWall[j].getRectangle()))//使用IntersectsWith()函数来进行碰撞检测
                    {
                        //移除墙体
                          listWall.Remove(listWall[j]);
                        //并且移除玩家子弹
                        listPlayerZD.Remove(listPlayerZD[i]);
                        break;
                    }
                }
            }
              #endregion

            #region 判断敌人是否和墙体发生了碰撞
            for (int i = 0; i < listWall.Count; i++)
            {
                for (int j = 0; j < listEnemyTank.Count; j++)
                {
                    if (listWall[i].getRectangle().IntersectsWith(listEnemyTank[j].getRectangle()))
                    {
                        //当敌人和墙体发生碰撞的时候 我们应该让敌人的坐标固定到
                        //碰撞的位置，不允许穿过墙体
                        //需要判断 敌人是从哪个方向过来发生碰撞的
                        switch (listEnemyTank[j].dir)
                        {
                            case Direction.up:
                                listEnemyTank[j].y = listWall[i].y+ listWall[i].height;
                                break;

                            case Direction.down:
                                listEnemyTank[j].x = listWall[i].y - listWall[i].height;
                                break;
                            case Direction.left:
                                listEnemyTank[j].x= listWall[i].x+ listWall[i].width;
                                break;
                            case Direction.right:
                                listEnemyTank[j].x = listWall[i].x - listWall[i].width;
                                break;
                        }
                    }
                }
            }
            #endregion


            #region 判断玩家坦克是否与敌人坦克碰撞           
                for (int j = 0; j < listEnemyTank.Count; j++)
                {
                    int oldx,oldy;
                    if (pt.getRectangle().IntersectsWith(listEnemyTank[j].getRectangle()))//使用IntersectsWith()函数来进行碰撞检测
                    {
                        pt.x=oldx;pt.y=oldy;
                        break;
                    }
                    else{
                         oldx=pt.x;oldy=pt.y;
                    }
                }
            }
            #endregion
        }
    

        public void  JudgeZB(int type)
    {
        switch(type)
    {
            case 0://吃到五角星时增加玩家子弹速度              
                    if(pt.ZDlevel<2)
                    pt.ZDlevel++;               
                break;
            case 1:               
                    for (int i = 0; i < listEnemyTank.Count; i++)
                    {
                        //把敌人坦克的生命值赋值为0
                        listEnemyTank[i].life = 0;
                        //调用敌人死亡的方法
                        listEnemyTank[i].IsOver();
                    }                
                break;
            case 2:            
                    for (int i = 0; i < listEnemyTank.Count; i++)
                    {                     
                        listEnemyTank[i].isStop = false;
                    }              
                break;
    }
    }
       
    }
}
