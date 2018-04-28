using System;
using System.IO;
using System.Collections.Generic;
using System.Windows.Forms;
using Newtonsoft.Json;
using AirplaneBookingDLL;

namespace AirplaneBookingSystem
{
    public partial class AirplaneBooking : Form
    {
        // Objects that are gonna be created so that new planes and passengers can be created
        Plane pl;
        Passenger ps;
        Flight fl;

        // List of all types of data
        List<Plane> AllPlanes;
        List<Flight> AllFlights;
        List<Passenger> AllPassengers;

        //Unique list of passenger names so that a single name can be seen for multiple tickets
        HashSet<string> AllPassengerNames;

        // Temp passenger to be used for a ticket
        string TempPassenger;

        public AirplaneBooking()
        {
            InitializeComponent();

            // Create blakn objects to be used
            ps = new Passenger();
            pl = new Plane();
            fl = new Flight();
            AllPassengerNames = new HashSet<string>();

            // Set all of the data to be used in the windows form
            ImportFileData();
            LoadFlightSchedules();
            LoadPassengerNames();
            LoadPassengerTickets();
        }

        public void ImportFileData()
        {
            // Load the data from JSON files for ease of use
            AllPlanes = LoadAll<Plane>("planes");
            AllFlights = LoadAll<Flight>("flights");
            AllPassengers = LoadAll<Passenger>("passengers");
        }

        public void LoadFlightSchedules()
        {
            // Add all of the flights to the list of all flights
            foreach (Flight f in AllFlights)
            {
                FlightsListBox.Items.Add(f.Time + "\t" + f.Date.ToShortDateString() + "\t" + f.Destination.Substring(0,3) + "\t\t" + f.Destination.Substring(4,3) + "\t\t" + f.FlightID);
            }
        }

        public void LoadPassengerTickets()
        {
            // Load the tickets for the combo box, where each passenger has one name, but can have multiple tickets assigned
            foreach (string p in AllPassengerNames)
            {
                PassengerTicketComboBox.Items.Add(p);
            }
        }

        public void LoadPassengerNames()
        {
            // Load all of the passenger names to be used for tickets
            foreach (Passenger p in AllPassengers)
            {
                AllPassengerNames.Add(p.FirstName + " " + p.LastName);
            }
        }

        // Get all of the data from the input forms from the different tabs
        private void FirstNameTextBox_TextChanged(object sender, EventArgs e)
        {
            ps.FirstName = FirstNameTextBox.Text;
        }

        private void LastNameTextBox_TextChanged(object sender, EventArgs e)
        {
            ps.LastName = LastNameTextBox.Text;
        }

        private void DestinationComboBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            ps.Destination = DestinationComboBox.SelectedItem.ToString();
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

        // Use a generic list to be populated based on the data type we want from the JSON file
        private List<T> LoadAll<T>(string Entity)
        {
            using (StreamReader r = new StreamReader(@"E:\Utility Programs\VS - C#\AirplaneBookingSystem\AirplaneBookingSystem\" + Entity + ".json"))
            {
                string list = r.ReadToEnd();
                return JsonConvert.DeserializeObject<List<T>>(list);
            }
        }

        // Serialize the generic list into a JSON file so we later access the data
        private void WriteTo<T>(string Entitiy, List<T> collection)
        {
            using (StreamWriter file = File.CreateText(@"E:\Utility Programs\VS - C#\AirplaneBookingSystem\AirplaneBookingSystem\" + Entitiy + ".json"))
            {
                JsonSerializer serializer = new JsonSerializer();
                serializer.Serialize(file, collection);
            }
        }

        // Check if the seat is free
        private void Check_Click(object sender, EventArgs e)
        {
            try
            {
                ps.CheckPassengerState();
            }
            catch (MissingFieldException mfe)
            {
                MessageBox.Show("Please enter the missing field(s).\n\n" + mfe.Message);
                return;
            }
            MessageBox.Show("Your seat is free.");
        }

        // Book the seat for the destination if such a flight exists
        private void BookSeat_Click(object sender, EventArgs e)
        {
            try
            {
                Check_Click(sender, e);
                ps.FindFlight(AllFlights);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }

            AllPassengers.Add(ps);
            WriteTo("passengers", AllPassengers);
        }

        // Get all of the data input for the plane form
        private void FlightIDTextBox_TextChanged(object sender, EventArgs e)
        {
            pl.ID = FlightIDTextBox.Text;
        }

        private void FlightDestinationComboBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            pl.Destination = FlightDestinationComboBox.SelectedItem.ToString();
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

        private void PassengerTicketComboBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            TempPassenger = PassengerTicketComboBox.SelectedItem.ToString();
        }

        // Save the plane and create a defaulted flight, no need to input more flight data since it's a demo program
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

        // Output all of the ticket infos for the passengers
        private void CheckPassengerButton_Click(object sender, EventArgs e)
        {
            TicketsListBox.Items.Clear();
            foreach (Passenger p in AllPassengers)
            {
                if ((p.FirstName + " " + p.LastName).Equals(TempPassenger) || p.FirstName.Equals(TempPassenger) || p.LastName.Equals(TempPassenger))
                {
                    TicketsListBox.Items.Add("Flight: " + p.FlightID);
                    TicketsListBox.Items.Add("Type: " + p.TicketType);
                    TicketsListBox.Items.Add("Date: " + p.TravelDate);
                    TicketsListBox.Items.Add("Name: " + p.FirstName + " " + p.LastName);
                    TicketsListBox.Items.Add("Seat: " + p.Seat);
                    TicketsListBox.Items.Add("Destination: " + p.Destination);
                    TicketsListBox.Items.Add("------------------------------");
                }
            }
        }
    }
}
