using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TankGameV1._0
{
    class ZiDanFather:GameObject
    {
        private Image img;

        public Image Img
        {
            get { return img; }
            set { img = value; }
        }

        public int power
        {
            get;
            set;
        }

        public ZiDanFather(TankFather tf, int speed, int life,  int power, Image img)
            : base(tf.x + tf.width / 2-6, tf.y+ tf.height / 2-6 , img.Width, img.Height, speed, life,tf. dir)
        {
            this.img = img;
        }
        public override void draw(Graphics g)
        {
            switch (this.dir)
            {
                case Direction.up:
                    this.y -= this.speed;
                    break;
                case Direction.down:
                    this.y += this.speed;
                    break;
                case Direction.left:
                    this.x -= this.speed;
                    break;
                case Direction.right:
                    this.x += this.speed;
                    break;
            }
            if (this.x <= 0)
            {
                x = -100;
            }
            if (this.y <= 0)
            {
                y = -100;
            }
            if (this.x >= 720)
            {
                this.x = 800;
            }
            if (this.y >= 600)
            {
                this.y = 800;
            }
            g.DrawImage(img, this.x, this.y);
        }
    }
}
