using System;
using System.IO;
using System.Collections.Generic;
using System.Windows.Forms;
using Newtonsoft.Json;

namespace AirplaneBookingSystem
{
    public partial class AirplaneBooking : Form
    {
        Plane pl;
        Passenger ps;
        Flight fl;

        List<Plane> AllPlanes;
        List<Flight> AllFlights;
        List<Passenger> AllPassengers;

        string TempPassenger;

        public AirplaneBooking()
        {
            InitializeComponent();

            ps = new Passenger();
            pl = new Plane();
            fl = new Flight();

            ImportFileData();
            LoadFlightSchedules();
        }

        public void ImportFileData()
        {
            AllPlanes = LoadAll<Plane>("planes");
            AllFlights = LoadAll<Flight>("flights");
            AllPassengers = LoadAll<Passenger>("passengers");
        }

        public void LoadFlightSchedules()
        {
            foreach (Flight f in AllFlights)
            {
                Flights.Text += f.Time + "    " + f.Date + "    " + f.To + "     " + f.From + "   " + f.FlightID + "\n";
            }
        }

        private void FirstNameTextBox_TextChanged(object sender, EventArgs e)
        {
            ps.FirstName = FirstNameTextBox.Text;
        }

        private void LastNameTextBox_TextChanged(object sender, EventArgs e)
        {
            ps.LastName = LastNameTextBox.Text;
        }

        private void DestinationTextBox_TextChanged(object sender, EventArgs e)
        {
            ps.Destination = DestinationTextBox.Text;
        }

        private void SelectedDate_ValueChanged(object sender, EventArgs e)
        {
            ps.TravelDate = SelectedDate.Value.Date;
        }

        private void TicketTypeCombo_SelectedIndexChanged(object sender, EventArgs e)
        {
            ps.TicketType = TicketTypeCombo.SelectedItem.ToString();
        }

        private void SeatRowCombo_SelectedIndexChanged(object sender, EventArgs e)
        {
            ps.Seat += SeatRowCombo.SelectedItem.ToString();
        }

        private void RowAlignmentCombo_SelectedIndexChanged(object sender, EventArgs e)
        {
            ps.Seat += RowAlignmentCombo.SelectedItem.ToString();
        }

        private List<T> LoadAll<T>(string Entity)
        {
            using (StreamReader r = new StreamReader(@"E:\Utility Programs\VS - C#\AirplaneBookingSystem\AirplaneBookingSystem\" + Entity + ".json"))
            {
                string list = r.ReadToEnd();
                return JsonConvert.DeserializeObject<List<T>>(list);
            }
        }

        private void WriteTo<T>(string Entitiy, List<T> collection)
        {
            using (StreamWriter file = File.CreateText(@"E:\Utility Programs\VS - C#\AirplaneBookingSystem\AirplaneBookingSystem\" + Entitiy + "852285825825852.json"))
            {
                JsonSerializer serializer = new JsonSerializer();
                serializer.Serialize(file, collection);
            }
        }

        private void Check_Click(object sender, EventArgs e)
        {
            try
            {
                ps.CheckPassengerState();
            }
            catch (MissingFieldException mfe)
            {
                MessageBox.Show("Please enter the missing field(s).\n\n" + mfe.Message);
            }
        }

        private void BookSeat_Click(object sender, EventArgs e)
        {
            try
            {
                ps.FindFlight(AllFlights);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }

            AllPassengers.Add(ps);
            WriteTo("passengers", AllPassengers);
        }

        private void FlightIDTextBox_TextChanged(object sender, EventArgs e)
        {
            pl.ID = FlightIDTextBox.Text;
        }

        private void DepartureTextBox_TextChanged(object sender, EventArgs e)
        {
            pl.TakeOffPort = DepartureTextBox.Text;
        }

        private void ArrivalTextBox_TextChanged(object sender, EventArgs e)
        {
            pl.ArrivalPort = ArrivalTextBox.Text;
        }

        private void StopoverTextBox_TextChanged(object sender, EventArgs e)
        {
            pl.Stopover = StopoverTextBox.Text;
        }

        private void PlaneTextBox_TextChanged(object sender, EventArgs e)
        {
            pl.Type = PlaneTextBox.Text;
        }

        private void PassengersTextBox_TextChanged(object sender, EventArgs e)
        {
            try
            {
                pl.NumberPassengers = Convert.ToInt16(PassengersTextBox.Text);
            }
            catch
            {

            }
        }

        private void RowsTextBox_TextChanged(object sender, EventArgs e)
        {
            try
            {
                pl.NumberRows = Convert.ToInt32(RowsTextBox.Text);
            }
            catch
            {

            }
        }

        private void DinningCheckBox_CheckedChanged(object sender, EventArgs e)
        {
            pl.Dinning = DinningCheckBox.Checked;
        }

        private void monthCalendar2_DateChanged(object sender, DateRangeEventArgs e)
        {
            monthCalendar2.MaxSelectionCount = 1;
            pl.TakeOffDate = monthCalendar2.SelectionStart;
        }

        private void monthCalendar1_DateChanged(object sender, DateRangeEventArgs e)
        {
            monthCalendar1.MaxSelectionCount = 1;
            pl.ArrivalDate = monthCalendar1.SelectionStart;
        }

        private void SavePlane_Click(object sender, EventArgs e)
        {
            try
            {
                pl.CheckPlaneState();
            }
            catch (MissingFieldException mfe)
            {
                MessageBox.Show("Please enter the missing field(s).\n\n" + mfe.Message);
                return;
            }

            fl.AddFlight(pl);
            AllFlights.Add(fl);
            WriteTo("flights", AllFlights);

            AllPlanes.Add(pl);
            WriteTo("planes", AllPlanes);
            MessageBox.Show("Plane has been added!");
        }

        private void CheckPassengerTextBox_TextChanged(object sender, EventArgs e)
        {
            TempPassenger = CheckPassengerTextBox.Text;
        }

        private void CheckPassengerButton_Click(object sender, EventArgs e)
        {
            foreach (Passenger p in AllPassengers)
            {
                if ((p.FirstName + " " + p.LastName).Equals(TempPassenger) || p.FirstName.Equals(TempPassenger) || p.LastName.Equals(TempPassenger))
                {
                    PassengerTicket.Text = "Flight: " + p.FlightID + "\n" +
                                           "Type: " + p.TicketType + "\n" +
                                           "Date: " + p.TravelDate + "\n" +
                                           "Name: " + p.FirstName + " " + p.LastName + "\n" +
                                           "Seat: " + p.Seat + "\n" +
                                           "Destination: " + p.Destination;
                }
            }
        }
    }
}
