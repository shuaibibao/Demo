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
    class EnemyTank:TankFather
    {
        #region 图片属性
        private static  Image[] imgs1 ={
                                  Resources.enemy1U,
                                  Resources.enemy1D,
                                  Resources.enemy1L,
                                  Resources.enemy1R
                           };//别忘记写“；”
        private static Image[] imgs2 ={
                                   Resources.enemy2U,
                                  Resources.enemy2D,
                                  Resources.enemy2L,
                                  Resources.enemy2R
                              };
        private static  Image[] imgs3={
                                   Resources.enemy3U,
                                  Resources.enemy3D,
                                  Resources.enemy3L,
                                  Resources.enemy3R
                              };
        #endregion
        //存储敌人坦克的速度
        private static int _speed;
        //存储敌人坦克的生命值
        private static int _life;

        public int EnemyTankType
        {
            set;
            get;
        }

        //通过一个静态方法设置敌人坦克的速度
        public static int setSpeed(int type)
        {
            switch (type)
            {
                case 0: _speed = 5;
                    break;
                case 1: _speed = 6;
                    break;
                case 2: _speed = 7;
                    break;
            }
            return _speed;
        }

        //通过一个静态方法设置敌人坦克的生命值

        public static int setLife(int type)
        {
            switch (type)
            {
                case 0:
                    _life = 1;
                    break;
                case 1:
                    _life = 2;
                    break;
                case 2:
                    _life = 3;
                    break;
            }
            return _life;
        }
        public EnemyTank(int x, int y, int type, Direction dir)
            : base(x, y, imgs1, setSpeed(type), setLife(type), dir)
        {
            this.EnemyTankType = type;
            born();
        }
        public int bornTiem = 0;
        //isMove 用来实现初始化闪烁现象，让坦克暂时不显示出来
        public bool isMove = false;
        //向窗体当中绘制敌人坦克
        public bool isStop = true;
        public int stopTime = 0;
        public override void draw(Graphics g)
        {
            bornTime++;
            if (bornTime % 20 == 0)
                isMove = true;
            if (isMove)
            {
                //一旦绘制，就要敌人坦克移动一下
                if (isStop)
                {
                    move();
                }
                else
                {
                    stopTime++;
                    if (stopTime %100 == 0)
                        isStop = true;
                }
                #region type判别
                switch (EnemyTankType)
                {
                    case 0:
                        switch (this.dir)
                        {
                            case Direction.up:
                                g.DrawImage(imgs1[0], this.x, this.y);
                                break;
                            case Direction.down:
                                g.DrawImage(imgs1[1], this.x, this.y);
                                break;
                            case Direction.left:
                                g.DrawImage(imgs1[2], this.x, this.y);
                                break;
                            case Direction.right:
                                g.DrawImage(imgs1[3], this.x, this.y);
                                break;
                        }
                        break;
                    case 1:
                        switch (this.dir)
                        {
                            case Direction.up:
                                g.DrawImage(imgs2[0], this.x, this.y);
                                break;
                            case Direction.down:
                                g.DrawImage(imgs2[1], this.x, this.y);
                                break;
                            case Direction.left:
                                g.DrawImage(imgs2[2], this.x, this.y);
                                break;
                            case Direction.right:
                                g.DrawImage(imgs2[3], this.x, this.y);
                                break;
                        }
                        break;
                    case 2:
                        switch (this.dir)
                        {
                            case Direction.up:
                                g.DrawImage(imgs3[0], this.x, this.y);
                                break;
                            case Direction.down:
                                g.DrawImage(imgs3[1], this.x, this.y);
                                break;
                            case Direction.left:
                                g.DrawImage(imgs3[2], this.x, this.y);
                                break;
                            case Direction.right:
                                g.DrawImage(imgs3[3], this.x, this.y);
                                break;
                        }
                        break;
                }
            }
            #endregion
            if (isStop)
            {
                if (r.Next(0, 100) < 3)
                    fire();
            }
        }
        public override void fire()
        {           
                    SingleObject.getSingle().addGameObject(new EnemyZD(this, 10, 10, 1));//把敌人子弹加入单列模式中去
        }
        static Random r = new Random();//静态的，在内存中是唯一的，这是很重要的
        public override void move()
        {
            base.move();
            //给一个很小的概率 产生随机数
            if (r.Next(0, 100) < 5)//%5的概率会改变方向
            {
                switch (r.Next(0, 4))
                {
                    case 0:
                        this.dir = Direction.up;
                        break;
                    case 1:
                        this.dir = Direction.down;
                        break;
                    case 2:
                        this.dir = Direction.left;
                        break;
                    case 3:
                        this.dir = Direction.right;
                        break;
                }
            }
        }

        public override void IsOver()
        {
            if (this.life <=0)
            {
                SingleObject.getSingle().addGameObject(new Boom(this.x - 25, this.y - 25));//坦克over的时候向单列设计模式中加入爆炸实例
                SingleObject.getSingle().removeGameObject(this);
                //播放死亡音乐
                SoundPlayer sp = new SoundPlayer(Resources.fire);
                sp.Play();
                //以一定的几率产生新的敌人坦克
                if (r.Next(0, 100) >= 50)
                {
                    SingleObject.getSingle().addGameObject(new EnemyTank(r.Next(0, 700), r.Next(0, 600), r.Next(0, 3), Direction.down));
                }
                if (r.Next(0,100) <10)
                { //敌人挂了产生一些装备
                    SingleObject.getSingle().addGameObject(new ZhuangBei(this.x, this.y, r.Next(0, 3)));
                }
            }
            else
            {
                SoundPlayer sp = new SoundPlayer(Resources.hit);
                sp.Play();
            }
        }

        public override void born()
        {
            SingleObject.getSingle().addGameObject(new TankBorn(this.x, this.y));
        }
    }
}
