using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AirplaneBookingSystem
{
    class Plane
    {
        public String ID { set; get; }
        public String TakeOffPort { set; get; }
        public String ArrivalPort { set; get; }
        public String Stopover { set; get; }
        public String Type { set; get; }
        public int NumberPassengers { set; get; }
        public int NumberRows { set; get; }
        public Boolean Dinning { set; get; }
        public DateTime TakeOff { set; get; }
        public DateTime Arrival { set; get; }
    }
}