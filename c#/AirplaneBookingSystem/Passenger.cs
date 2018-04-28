using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AirplaneBookingDLL
{
    public class Passenger
    {
        public Flight fl { set; get; }
        public String Seat { set; get; }
        public String FlightID { set; get; }
        public String LastName { set; get; }
        public String FirstName { set; get; }
        public String TicketType { set; get; }
        public String Destination { set; get; }
        public DateTime TravelDate { set; get; }

        // Make sure that there are not empty data fields
        public void CheckPassengerState()
        {
            if (string.IsNullOrEmpty(FirstName))
            {
                throw new MissingFieldException("Please Enter your First Name!");
            }
            if (string.IsNullOrEmpty(LastName))
            {
                throw new MissingFieldException("Please Enter your Last Name!");
            }
            if (string.IsNullOrEmpty(Seat))
            {
                throw new MissingFieldException("Please Enter your Seat!");
            }
            if (string.IsNullOrEmpty(Destination))
            {
                throw new MissingFieldException("Please Enter your Destination!");
            }
            if (TravelDate.Equals(null))
            {
                throw new MissingFieldException("Please Enter your Date of Travel!");
            }
            if (string.IsNullOrEmpty(TicketType))
            {
                throw new MissingFieldException("Please Enter your Ticket Type!");
            }
        }

        // Find a flight for e destination and assign that flight
        public void FindFlight(List<Flight> AllFlights)
        {
            foreach (Flight f in AllFlights)
            {
                if (Destination.Equals(f.Destination) && TravelDate.Equals(f.Date))
                {
                    Destination = f.Destination;
                    FlightID = f.FlightID;
                    fl = f;
                    return;
                }
            }
            throw new Exception("No flight found!");
        }
    }
}
