using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TankGameV1._0
{
    abstract class TankFather:GameObject
    {
        private Image[] imgs = new Image[] { };//注意这样的定义方式

        public TankFather(int x, int y, Image[] imgs, int speed, int life, Direction dir)
            : base(x,y,imgs[0].Width,imgs[0].Height,speed,life,dir)
        {
            this.imgs = imgs;
        }

        public override void draw(Graphics g)
        {
            switch (this.dir)
            {
                case Direction.up:
                    g.DrawImage(imgs[0], this.x,this.y);
                    break;
                case Direction.down:
                    g.DrawImage(imgs[1],this.x,this.y);
                    break;
                case Direction.left:
                    g.DrawImage(imgs[2],this.x,this.y);
                    break;
                case Direction.right:
                    g.DrawImage(imgs[3], this.x, this.y);
                    break;
            }
        }
        public abstract void IsOver();
        public abstract void fire();

    }
}
