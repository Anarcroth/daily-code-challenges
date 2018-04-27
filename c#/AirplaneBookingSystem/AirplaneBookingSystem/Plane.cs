using System;

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
        public DateTime TakeOffDate { set; get; }
        public DateTime ArrivalDate { set; get; }

        public void CheckPlaneState()
        {
            if (string.IsNullOrEmpty(ID))
            {
                throw new MissingFieldException("Please enter a Plane ID!");
            }
            if (string.IsNullOrEmpty(TakeOffPort))
            {
                throw new MissingFieldException("Please enter a Plane ID!");
            }
            if (string.IsNullOrEmpty(ArrivalPort))
            {
                throw new MissingFieldException("Please enter a Plane ID!");
            }
            if (string.IsNullOrEmpty(Type))
            {
                throw new MissingFieldException("Please enter a Plane ID!");
            }
            if (NumberPassengers < 1)
            {
                throw new MissingFieldException("Please enter a Plane ID!");
            }
            if (NumberRows < 1)
            {
                throw new MissingFieldException("Please enter a Plane ID!");
            }
            if (TakeOffDate.Equals(null))
            {
                throw new MissingFieldException("Please enter a Plane ID!");
            }
            if (ArrivalDate.Equals(null))
            {
                throw new MissingFieldException("Please enter a Plane ID!");
            }
        }
    }
}