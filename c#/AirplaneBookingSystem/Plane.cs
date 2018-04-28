using System;

namespace AirplaneBookingDLL
{
    public class Plane
    {
        public String ID { set; get; }
        public String Destination { set; get; }
        public String Stopover { set; get; }
        public String Type { set; get; }
        public int NumberPassengers { set; get; }
        public int NumberRows { set; get; }
        public Boolean Dinning { set; get; }
        public DateTime TakeOffDate { set; get; }
        public DateTime ArrivalDate { set; get; }

        // Make sure that the important data is present for the plane, we can also have empty Stopovers because they are not mandatory for some planes
        public void CheckPlaneState()
        {
            if (string.IsNullOrEmpty(ID))
            {
                throw new MissingFieldException("Please enter a Plane ID!");
            }
            if (string.IsNullOrEmpty(Destination))
            {
                throw new MissingFieldException("Please enter a Destination!");
            }
            if (string.IsNullOrEmpty(Type))
            {
                throw new MissingFieldException("Please enter a Type!");
            }
            if (NumberPassengers < 1)
            {
                throw new MissingFieldException("Please enter a valid number of passengers!");
            }
            if (NumberRows < 1)
            {
                throw new MissingFieldException("Please enter a valid number of rows!");
            }
            if (TakeOffDate.Equals(null))
            {
                throw new MissingFieldException("Please enter a Take Off Date!");
            }
            if (ArrivalDate.Equals(null))
            {
                throw new MissingFieldException("Please enter an Arrival Date!");
            }
        }
    }
}