using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TankGameV1._0
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            //这时候要对我们的游戏进行初始化
            initialGame();
        }
        private void initialGame()
        {
            SingleObject.getSingle().addGameObject(new PlayerTank(200,200,10,10,Direction.up));
            SetEnemyTanks();//用来初始化敌人坦克
        }
        Random r = new Random();//产生一个随机数种子
        /// <summary>
        ///初始化敌人坦克对象
        /// </summary>
        public void SetEnemyTanks()
        {
            for (int i = 0; i < 8; i++)
            {
                SingleObject.getSingle().addGameObject(new EnemyTank(r.Next(0, this.Width), r.Next(0, this.Height), r.Next(0, 3), Direction.down));
            }

        }
        private void Form1_Paint(object sender, PaintEventArgs e)//用来绘制所有的GameObject
        {
            SingleObject.getSingle().draw(e.Graphics);
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            SingleObject.getSingle().pt.keyDown(e);
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            //可以实时的对窗口进行重绘
            this.Invalidate();
            SingleObject.getSingle().PZJC();//用来实时的检测是否碰撞
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //让控件不闪烁
            this.SetStyle(ControlStyles.OptimizedDoubleBuffer | ControlStyles.ResizeRedraw | ControlStyles.AllPaintingInWmPaint, true); 
        }
    }
}
