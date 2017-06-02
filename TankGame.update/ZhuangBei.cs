using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TankGameV1._0.Properties;

namespace TankGameV1._0
{
    class ZhuangBei:GameObject
    {
        private static Image imgStar = Resources.star;
        private static Image imgBomb = Resources.bomb;
        private static Image imgTimer = Resources.timer;

        /// <summary>
        /// 装备的类型  0  代表 五角星 1代表地雷 2代表计时器
        /// </summary>
        public int ZBType
        {
            get;
            set;
        }

        public ZhuangBei(int x, int y, int type)
            : base(x, y, imgStar.Width, imgStar.Height,0,0,Direction.up)
        {
            this.ZBType = type;
        }

        public override void draw(Graphics g)
        {
            switch (ZBType)
            {
                case 0:
                    g.DrawImage(imgStar, this.x, this.y);
                    break;
                case 1:
                    g.DrawImage(imgBomb, this.x, this.y);
                    break;
                case 2:
                    g.DrawImage(imgTimer, this.x, this.y);
                    break;
            }
        }
    }
}
