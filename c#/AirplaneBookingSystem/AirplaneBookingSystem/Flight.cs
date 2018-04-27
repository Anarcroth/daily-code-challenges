using System;

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

        public void AddFlight(Plane pl)
        {
            this.pl = pl;
            To = pl.ArrivalPort;
            From = pl.TakeOffPort;
            Time = "14:05";
            Date = pl.ArrivalDate;
            PlaneID = pl.ID;
            FlightID = "AAD123";
        }
    }
}
