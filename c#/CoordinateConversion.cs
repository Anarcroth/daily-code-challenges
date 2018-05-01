using System;
using System.Windows.Forms;

namespace AnglesAndDegreeCalculator
{
    public partial class CoordinateConversion : Form
    {
        // Cartesian Plane Points
        int PointAX;
        int PointAY;

        // Polar Plane Points
        int PointXR;
        double PointXD;

        public CoordinateConversion()
        {
            InitializeComponent();
        }

        // Try-catch all of the inputs in order to make sure that they are numbers
        private void PA_X_TextChanged(object sender, EventArgs e)
        {
            try
            {
                PointAX = Convert.ToInt32(PA_X.Text);
            }
            catch
            {

            }
        }

        private void PA_Y_TextChanged(object sender, EventArgs e)
        {
            try
            {
                PointAY = Convert.ToInt32(PA_Y.Text);
            }
            catch
            {

            }
        }

        private void PX_R_TextChanged(object sender, EventArgs e)
        {
            try
            {
                PointXR = Convert.ToInt32(PX_R.Text);
            }
            catch
            {

            }
        }

        private void PX_D_TextChanged(object sender, EventArgs e)
        {
            try
            {
                PointXD = Convert.ToDouble(PX_D.Text);
            }
            catch
            {

            }
        }

        private void Convert_Click(object sender, EventArgs e)
        {
            int TempCartX = CalcX(PointXR, PointXD);
            int TempCartY = CalcY(PointXR, PointXD);

            ConvertedPolar.Text = "(" + TempCartX + ", " + TempCartY + ")";

            int TempPolarR = CalcR(PointAX, PointAY);
            double TempPolarD = CalcDegrees(PointAX, PointAY);

            ConvertedCartesian.Text = "(" + TempPolarR + ", " + TempPolarD + ")";
        }

        // Formulas for converting from polar to cartesian plane
        private int  CalcX(int r, double f)
        {
            return Convert.ToInt32(r * Math.Cos(f));
        }

        private int CalcY(int r, double f)
        {
            return Convert.ToInt32(r * Math.Sin(f));
        }

        // Formulas for converting from cartesian to polar plane
        private int CalcR(int x, int y)
        {
            return Convert.ToInt32(Math.Sqrt(Math.Pow(x, 2) + Math.Pow(y, 2)));
        }

        private double CalcDegrees(int x, int y)
        {
            return Math.Round(Math.Pow(Math.Tan(y / x), -1), 2);
        }
    }
}
