using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TankGameV1._0
{
    enum  Direction{
        left,
        up,
        down,
        right,
    }
    abstract class GameObject
    {
        #region 游戏对象的属性
        public int x
        {
            get;
            set;
        }
        public int y
        {
            get;
            set;
        }
        public int width
        {
            get;
            set;
        }
        public int height
        {
            get;
            set;
        }
        public int speed
        {
            get;
            set;
        }
        public int life
        {
            get;
            set;
        }
        public Direction dir
        {
            get;
            set;
        }
        #endregion
        public GameObject(int x, int y, int width, int height, int speed, int life, Direction dir)
        {
            this.x = x;
            this.y = y;
            this.width = width;
            this.height = height;
            this.speed = speed;
            this.life=life;
            this.dir=dir;
        }
        public abstract void draw(Graphics g);//定义抽象方法
        public virtual void move()//子类可以进行选择性的重写
        {
            switch (this.dir)
            {
                case Direction.up:
                    this.y-=this.speed;
                    break;
                case Direction.down:
                    this.y+=this.speed;
                    break;
                case Direction.left:
                    this.x-=this.speed;
                    break;
                case Direction.right:
                    this.x+=this.speed;
                    break;
            }
            if (this.x <= 0)
            {
                x = 0;
            }
            if (this.y <= 0)
            {
                y = 0;
            }
            if (this.x >= 720)
            {
                this.x = 720;
            }
            if (this.y >= 600)
            {
                this.y = 600;
            }
        }
        public Rectangle getRectangle()
        {
            return new Rectangle(this.x, this.y, this.width, this.height);
        }//用于碰撞检测
    }

}
