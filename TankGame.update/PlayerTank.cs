using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Media;
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
        {
            born();
        }

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

        public int ZDlevel;
        public override void fire()
        {
            switch (ZDlevel)
            {
                case 0:
                    SingleObject.getSingle().addGameObject(new PlayerZD(this, 10, 10, 1));
                    break;
                case 1:
                    SingleObject.getSingle().addGameObject(new PlayerZD(this, 20, 10, 1));
                    break;
                case 2:
                    SingleObject.getSingle().addGameObject(new PlayerZD(this, 30, 10, 1));
                    break;
            }
          
        }

        public override void IsOver()
        {
            SoundPlayer sp = new SoundPlayer(Resources.hit);
            sp.Play();
            //SingleObject.getSingle().addGameObject(new Boom(this.x- 25, this.y - 25));
        }

        public override void born()
        {
            SingleObject.getSingle().addGameObject(new TankBorn(this.x, this.y));
        }
    }
}
