using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using TankGameV1._0.Properties;

namespace TankGameV1._0
{
    class PlayerTank:TankFather
    {
        private static Image[] imgs = {  
                               Resources.p1tankU,
                               Resources.p1tankD,
                               Resources.p1tankL,
                               Resources.p1tankR,
                               };
        public PlayerTank(int x, int y, int speed, int life, Direction dir)
            : base(x,y,imgs,speed,life,dir)
        {}

        public void keyDown(KeyEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.W:
                    this.dir = Direction.up;
                    base.move();//base代表的是一个父类空间的引用；
                    break;
                case Keys.A:
                    this.dir = Direction.left;
                    base.move();
                    break;
                case Keys.S:
                    this.dir = Direction.down;
                    base.move();
                    break;
                case Keys.D:
                    this.dir = Direction.right;
                    base.move();
                    break;
                case Keys.K:
                    fire();
                    break;
            }
            
        }

        public override void fire()
        {
            SingleObject.getSingle().addGameObject(new PlayerZD(this, 10, 10, 1));
        }

        public override void IsOver()
        {
            SingleObject.getSingle().addGameObject(new Boom(this.x- 25, this.y - 25));
        }

    }
}
