using System;
using System.IO;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Newtonsoft.Json;

namespace AirplaneBookingSystem
{
    public partial class AirplaneBooking : Form
    {
        Plane pl;
        Passenger ps;

        List<Plane> AllPlanes;
        List<Flight> AllFlights;
        List<Passenger> AllPassengers;

        ObservableCollection<int> RowsList;
        ObservableCollection<String> Alignments;
        ObservableCollection<String> TicketTypes;

        public AirplaneBooking()
        {
            InitializeComponent();

            ps = new Passenger();

            PopulateRows();
            PopulateAlignments();
            populateTicketTypes();

            LoadData();
        }

        public void LoadData()
        {
            AllPlanes = JsonConvert.DeserializeObject<List<Plane>>(LoadAll("planes"));
            AllFlights = JsonConvert.DeserializeObject<List<Flight>>(LoadAll("flights"));
            AllPassengers = JsonConvert.DeserializeObject<List<Passenger>>(LoadAll("passengers"));
        }

        private void populateTicketTypes()
        {
            TicketTypes = new ObservableCollection<String>();
            TicketTypes.Add("One-Way");
            TicketTypes.Add("Two-Way");
            TicketTypeCombo.DataSource = TicketTypes;
        }

        private void PopulateRows()
        {
            RowsList = new ObservableCollection<int>();
            for (int i = 1; i <= 100; i++) { RowsList.Add(i); }
            SeatRowCombo.DataSource = RowsList;
        }

        private void PopulateAlignments()
        {
            Alignments = new ObservableCollection<String>();
            Alignments.Add("A");
            Alignments.Add("B");
            Alignments.Add("C");
            Alignments.Add("D");
            Alignments.Add("E");
            Alignments.Add("F");
            RowAlignmentCombo.DataSource = Alignments;
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

        private string LoadAll(string Entity)
        {
            using (StreamReader r = new StreamReader(@"E:\Utility Programs\VS - C#\AirplaneBookingSystem\AirplaneBookingSystem\" + Entity + ".json"))
            {
                return r.ReadToEnd();
            }
        }

        private void WriteToJson()
        {
            using (StreamWriter file = File.CreateText(@"E:\Utility Programs\VS - C#\AirplaneBookingSystem\AirplaneBookingSystem\passengers.json"))
            {
                JsonSerializer serializer = new JsonSerializer();
                serializer.Serialize(file, AllPassengers);
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
            MessageBox.Show("Your seat is free!");
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
            WriteToJson();

            MessageBox.Show("Your flight has been saved!");
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
            pl.NumberPassengers = PassengersTextBox.Text
        }

        private void RowsTextBox_TextChanged(object sender, EventArgs e)
        {

        }

        private void DinningCheckBox_CheckedChanged(object sender, EventArgs e)
        {

        }
    }
}
