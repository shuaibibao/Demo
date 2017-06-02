using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TankGameV1._0.Properties;

namespace TankGameV1._0
{
    class Wall:GameObject
    {
        private static Image img = Resources.wall;
        public Wall(int x, int y)
            : base(x, y, img.Width, img.Height,0,0,Direction.up)
        { }


        public override void draw(Graphics g)
            {
                g.DrawImage(img, this.x, this.y);
            }    
    }
}
