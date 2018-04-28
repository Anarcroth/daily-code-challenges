using System;

namespace AirplaneBookingDLL
{
    public class Flight
    {
        public Plane pl { set; get; }
        public String Destination { set; get; }
        public String Time { set; get; }
        public DateTime Date { set; get; }
        public String PlaneID { set; get; }
        public String FlightID { set; get; }

        // Add the flight from the saved plane
        public void AddFlight(Plane pl)
        {
            this.pl = pl;
            Destination = pl.Destination;
            Time = "14:05";
            Date = pl.ArrivalDate;
            PlaneID = pl.ID;
            FlightID = "AAD123";
        }
    }
}
