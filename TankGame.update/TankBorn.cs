using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TankGameV1._0.Properties;

namespace TankGameV1._0
{
    class TankBorn : GameObject
    {
        //导入闪烁的图片
        private Image[] imgs = { 
                              Resources.born1,
                              Resources.born2,
                              Resources.born3,
                              Resources.born4
                               };
        public TankBorn(int x, int y)
            : base(x, y, 0, 0, 0, 0, Direction.up)
        {
        }
        int time = 0;
        public override void draw(Graphics g)
        {
            time++;//防止循环太快看不到图片
            for (int i = 0; i < imgs.Length; i++)
            {
                switch (time %10)
                {
                    case 1:
                        g.DrawImage(imgs[0], this.x, this.y); break;
                    case 3:
                        g.DrawImage(imgs[1], this.x, this.y);
                        break;
                    case 5:
                        g.DrawImage(imgs[2], this.x, this.y);
                        break;
                    case 7:
                        g.DrawImage(imgs[3], this.x, this.y);
                        break;
                }
            }
            //当for循环结束之后 也就是闪烁图片播放完成了
            //这个时候 我们应该将闪烁的图片从屏幕上移除
            if (time %15== 0)
            {
                SingleObject.getSingle().removeGameObject(this);
            }
        }
    }
}
