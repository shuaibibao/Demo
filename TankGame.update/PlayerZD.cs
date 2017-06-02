using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TankGameV1._0.Properties;

namespace TankGameV1._0
{
    class PlayerZD:ZiDanFather
    {
        private static Image img = Resources.tankmissile;

        public PlayerZD(TankFather tf, int speed, int life, int power)
            : base(tf, speed, life, power, img)
        {
            this.power = power;//这步很重要，不然子类子弹没有power值
        }


    }
}
