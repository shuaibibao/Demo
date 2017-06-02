using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TankGameV1._0.Properties;

namespace TankGameV1._0
{
    class Boom:GameObject
    {
        #region//导入资源图片
        private Image[] imgs ={
                                 Resources.blast1,
                                  Resources.blast2,
                                   Resources.blast3,
                                    Resources.blast4,
                                     Resources.blast5,
                                      Resources.blast6,
                                       Resources.blast7,
                                        Resources.blast8
                             };//别忘记加分号
        #endregion
        public Boom(int x, int y)
            : base(x,y,0,0,0,0,Direction.up)
        {
        }
        public override void draw(Graphics g)
        {
            for (int i = 0; i < imgs.Length; i++)
            {
                g.DrawImage(imgs[i], this.x, this.y);
            }
            //爆炸图片播放完成  就销毁自己
            SingleObject.getSingle().removeGameObject(this);
        }

    }
}
