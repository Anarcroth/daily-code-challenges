using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AirplaneBookingSystem
{
    class Flight
    {
        public Plane pl { set; get; }
        public String To { set; get; }
        public String From { set; get; }
        public String Time { set; get; }
        public DateTime Date { set; get; }
        public String PlaneID { set; get; }
        public String FlightID { set; get; }
    }
}
