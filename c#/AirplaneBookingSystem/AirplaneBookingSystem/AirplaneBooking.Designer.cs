namespace AirplaneBookingSystem
{
    partial class AirplaneBooking
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.FirstName = new System.Windows.Forms.Label();
            this.LastName = new System.Windows.Forms.Label();
            this.SelectDate = new System.Windows.Forms.Label();
            this.Destination = new System.Windows.Forms.Label();
            this.TicketType = new System.Windows.Forms.Label();
            this.Check = new System.Windows.Forms.Button();
            this.TicketTypeCombo = new System.Windows.Forms.ComboBox();
            this.SelectedDate = new System.Windows.Forms.DateTimePicker();
            this.FirstNameTextBox = new System.Windows.Forms.TextBox();
            this.NewBooking = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.BookSeat = new System.Windows.Forms.Button();
            this.RowAlignmentCombo = new System.Windows.Forms.ComboBox();
            this.SeatAlignment = new System.Windows.Forms.Label();
            this.SeatRowCombo = new System.Windows.Forms.ComboBox();
            this.SeatRow = new System.Windows.Forms.Label();
            this.DestinationTextBox = new System.Windows.Forms.TextBox();
            this.LastNameTextBox = new System.Windows.Forms.TextBox();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.tabPage3 = new System.Windows.Forms.TabPage();
            this.SavePlane = new System.Windows.Forms.Button();
            this.ArrivalDate = new System.Windows.Forms.Label();
            this.TakeOffDate = new System.Windows.Forms.Label();
            this.monthCalendar2 = new System.Windows.Forms.MonthCalendar();
            this.monthCalendar1 = new System.Windows.Forms.MonthCalendar();
            this.DinningCheckBox = new System.Windows.Forms.CheckBox();
            this.Rows = new System.Windows.Forms.Label();
            this.RowsTextBox = new System.Windows.Forms.TextBox();
            this.Dinning = new System.Windows.Forms.Label();
            this.PassengersTextBox = new System.Windows.Forms.TextBox();
            this.PlaneTextBox = new System.Windows.Forms.TextBox();
            this.Stopovers = new System.Windows.Forms.Label();
            this.StopoverTextBox = new System.Windows.Forms.TextBox();
            this.Plane = new System.Windows.Forms.Label();
            this.PassengerNumber = new System.Windows.Forms.Label();
            this.ArrivalTextBox = new System.Windows.Forms.TextBox();
            this.DepartureTextBox = new System.Windows.Forms.TextBox();
            this.FlightID = new System.Windows.Forms.Label();
            this.FlightIDTextBox = new System.Windows.Forms.TextBox();
            this.DepartureAirport = new System.Windows.Forms.Label();
            this.ArrivalAirport = new System.Windows.Forms.Label();
            this.tabPage4 = new System.Windows.Forms.TabPage();
            this.Flights = new System.Windows.Forms.Label();
            this.FlightTab = new System.Windows.Forms.Label();
            this.FromTab = new System.Windows.Forms.Label();
            this.ToTab = new System.Windows.Forms.Label();
            this.DateTab = new System.Windows.Forms.Label();
            this.TimeTab = new System.Windows.Forms.Label();
            this.CheckPassengerButton = new System.Windows.Forms.Button();
            this.CheckPassenger = new System.Windows.Forms.Label();
            this.CheckPassengerTextBox = new System.Windows.Forms.TextBox();
            this.PassengerTicket = new System.Windows.Forms.Label();
            this.NewBooking.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.tabPage2.SuspendLayout();
            this.tabPage3.SuspendLayout();
            this.tabPage4.SuspendLayout();
            this.SuspendLayout();
            // 
            // FirstName
            // 
            this.FirstName.AutoSize = true;
            this.FirstName.Location = new System.Drawing.Point(23, 27);
            this.FirstName.Name = "FirstName";
            this.FirstName.Size = new System.Drawing.Size(57, 13);
            this.FirstName.TabIndex = 0;
            this.FirstName.Text = "First Name";
            // 
            // LastName
            // 
            this.LastName.AutoSize = true;
            this.LastName.Location = new System.Drawing.Point(23, 53);
            this.LastName.Name = "LastName";
            this.LastName.Size = new System.Drawing.Size(58, 13);
            this.LastName.TabIndex = 1;
            this.LastName.Text = "Last Name";
            // 
            // SelectDate
            // 
            this.SelectDate.AutoSize = true;
            this.SelectDate.Location = new System.Drawing.Point(23, 108);
            this.SelectDate.Name = "SelectDate";
            this.SelectDate.Size = new System.Drawing.Size(63, 13);
            this.SelectDate.TabIndex = 2;
            this.SelectDate.Text = "Select Date";
            // 
            // Destination
            // 
            this.Destination.AutoSize = true;
            this.Destination.Location = new System.Drawing.Point(23, 79);
            this.Destination.Name = "Destination";
            this.Destination.Size = new System.Drawing.Size(60, 13);
            this.Destination.TabIndex = 3;
            this.Destination.Text = "Destination";
            // 
            // TicketType
            // 
            this.TicketType.AutoSize = true;
            this.TicketType.Location = new System.Drawing.Point(23, 131);
            this.TicketType.Name = "TicketType";
            this.TicketType.Size = new System.Drawing.Size(64, 13);
            this.TicketType.TabIndex = 4;
            this.TicketType.Text = "Ticket Type";
            // 
            // Check
            // 
            this.Check.Location = new System.Drawing.Point(212, 209);
            this.Check.Name = "Check";
            this.Check.Size = new System.Drawing.Size(75, 23);
            this.Check.TabIndex = 5;
            this.Check.Text = "Check";
            this.Check.UseVisualStyleBackColor = true;
            this.Check.Click += new System.EventHandler(this.Check_Click);
            // 
            // TicketTypeCombo
            // 
            this.TicketTypeCombo.FormattingEnabled = true;
            this.TicketTypeCombo.Items.AddRange(new object[] {
            "One-Way",
            "Two-Way"});
            this.TicketTypeCombo.Location = new System.Drawing.Point(132, 128);
            this.TicketTypeCombo.Name = "TicketTypeCombo";
            this.TicketTypeCombo.Size = new System.Drawing.Size(155, 21);
            this.TicketTypeCombo.TabIndex = 6;
            this.TicketTypeCombo.SelectedIndexChanged += new System.EventHandler(this.TicketTypeCombo_SelectedIndexChanged);
            // 
            // SelectedDate
            // 
            this.SelectedDate.Location = new System.Drawing.Point(132, 102);
            this.SelectedDate.Name = "SelectedDate";
            this.SelectedDate.Size = new System.Drawing.Size(155, 20);
            this.SelectedDate.TabIndex = 7;
            this.SelectedDate.ValueChanged += new System.EventHandler(this.SelectedDate_ValueChanged);
            // 
            // FirstNameTextBox
            // 
            this.FirstNameTextBox.Location = new System.Drawing.Point(132, 24);
            this.FirstNameTextBox.Name = "FirstNameTextBox";
            this.FirstNameTextBox.Size = new System.Drawing.Size(155, 20);
            this.FirstNameTextBox.TabIndex = 8;
            this.FirstNameTextBox.TextChanged += new System.EventHandler(this.FirstNameTextBox_TextChanged);
            // 
            // NewBooking
            // 
            this.NewBooking.AccessibleName = "";
            this.NewBooking.Controls.Add(this.tabPage1);
            this.NewBooking.Controls.Add(this.tabPage2);
            this.NewBooking.Controls.Add(this.tabPage3);
            this.NewBooking.Controls.Add(this.tabPage4);
            this.NewBooking.Location = new System.Drawing.Point(1, 1);
            this.NewBooking.Name = "NewBooking";
            this.NewBooking.SelectedIndex = 0;
            this.NewBooking.Size = new System.Drawing.Size(549, 400);
            this.NewBooking.TabIndex = 9;
            this.NewBooking.Tag = "";
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.BookSeat);
            this.tabPage1.Controls.Add(this.RowAlignmentCombo);
            this.tabPage1.Controls.Add(this.SeatAlignment);
            this.tabPage1.Controls.Add(this.SeatRowCombo);
            this.tabPage1.Controls.Add(this.SeatRow);
            this.tabPage1.Controls.Add(this.DestinationTextBox);
            this.tabPage1.Controls.Add(this.LastNameTextBox);
            this.tabPage1.Controls.Add(this.FirstName);
            this.tabPage1.Controls.Add(this.Check);
            this.tabPage1.Controls.Add(this.TicketTypeCombo);
            this.tabPage1.Controls.Add(this.SelectedDate);
            this.tabPage1.Controls.Add(this.FirstNameTextBox);
            this.tabPage1.Controls.Add(this.LastName);
            this.tabPage1.Controls.Add(this.SelectDate);
            this.tabPage1.Controls.Add(this.Destination);
            this.tabPage1.Controls.Add(this.TicketType);
            this.tabPage1.Location = new System.Drawing.Point(4, 22);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(541, 374);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "tabPage1";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // BookSeat
            // 
            this.BookSeat.Location = new System.Drawing.Point(212, 238);
            this.BookSeat.Name = "BookSeat";
            this.BookSeat.Size = new System.Drawing.Size(75, 23);
            this.BookSeat.TabIndex = 15;
            this.BookSeat.Text = "Book Seat";
            this.BookSeat.UseVisualStyleBackColor = true;
            this.BookSeat.Click += new System.EventHandler(this.BookSeat_Click);
            // 
            // RowAlignmentCombo
            // 
            this.RowAlignmentCombo.FormattingEnabled = true;
            this.RowAlignmentCombo.Items.AddRange(new object[] {
            "A",
            "B",
            "C",
            "D",
            "E",
            "F"});
            this.RowAlignmentCombo.Location = new System.Drawing.Point(132, 182);
            this.RowAlignmentCombo.Name = "RowAlignmentCombo";
            this.RowAlignmentCombo.Size = new System.Drawing.Size(155, 21);
            this.RowAlignmentCombo.TabIndex = 14;
            this.RowAlignmentCombo.SelectedIndexChanged += new System.EventHandler(this.RowAlignmentCombo_SelectedIndexChanged);
            // 
            // SeatAlignment
            // 
            this.SeatAlignment.AutoSize = true;
            this.SeatAlignment.Location = new System.Drawing.Point(23, 185);
            this.SeatAlignment.Name = "SeatAlignment";
            this.SeatAlignment.Size = new System.Drawing.Size(78, 13);
            this.SeatAlignment.TabIndex = 13;
            this.SeatAlignment.Text = "Seat Alignment";
            // 
            // SeatRowCombo
            // 
            this.SeatRowCombo.FormattingEnabled = true;
            this.SeatRowCombo.Items.AddRange(new object[] {
            "1",
            "2",
            "3",
            "4",
            "5",
            "6",
            "7",
            "8",
            "9",
            "10",
            "11",
            "12",
            "13",
            "14",
            "15",
            "16",
            "17",
            "18",
            "19",
            "20",
            "21",
            "22",
            "23",
            "24",
            "25",
            "26",
            "27",
            "28",
            "29",
            "30",
            "31",
            "32",
            "33",
            "34",
            "35",
            "36",
            "37",
            "38",
            "39",
            "40",
            "41",
            "42",
            "43",
            "44",
            "45",
            "46",
            "47",
            "48",
            "49",
            "50",
            "51",
            "52",
            "53",
            "54",
            "55",
            "56",
            "57",
            "58",
            "59",
            "60",
            "61",
            "62",
            "63",
            "64",
            "65",
            "66",
            "67",
            "68",
            "69",
            "70",
            "71",
            "72",
            "73",
            "74",
            "75",
            "76",
            "77",
            "78",
            "79",
            "80",
            "81",
            "82",
            "83",
            "84",
            "85",
            "86",
            "87",
            "88",
            "89",
            "90",
            "91",
            "92",
            "93",
            "94",
            "95",
            "96",
            "97",
            "98",
            "99",
            "100"});
            this.SeatRowCombo.Location = new System.Drawing.Point(132, 155);
            this.SeatRowCombo.Name = "SeatRowCombo";
            this.SeatRowCombo.Size = new System.Drawing.Size(155, 21);
            this.SeatRowCombo.TabIndex = 12;
            this.SeatRowCombo.SelectedIndexChanged += new System.EventHandler(this.SeatRowCombo_SelectedIndexChanged);
            // 
            // SeatRow
            // 
            this.SeatRow.AutoSize = true;
            this.SeatRow.Location = new System.Drawing.Point(23, 158);
            this.SeatRow.Name = "SeatRow";
            this.SeatRow.Size = new System.Drawing.Size(54, 13);
            this.SeatRow.TabIndex = 11;
            this.SeatRow.Text = "Seat Row";
            // 
            // DestinationTextBox
            // 
            this.DestinationTextBox.Location = new System.Drawing.Point(132, 76);
            this.DestinationTextBox.Name = "DestinationTextBox";
            this.DestinationTextBox.Size = new System.Drawing.Size(155, 20);
            this.DestinationTextBox.TabIndex = 10;
            this.DestinationTextBox.TextChanged += new System.EventHandler(this.DestinationTextBox_TextChanged);
            // 
            // LastNameTextBox
            // 
            this.LastNameTextBox.Location = new System.Drawing.Point(132, 50);
            this.LastNameTextBox.Name = "LastNameTextBox";
            this.LastNameTextBox.Size = new System.Drawing.Size(155, 20);
            this.LastNameTextBox.TabIndex = 9;
            this.LastNameTextBox.TextChanged += new System.EventHandler(this.LastNameTextBox_TextChanged);
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.PassengerTicket);
            this.tabPage2.Controls.Add(this.CheckPassengerTextBox);
            this.tabPage2.Controls.Add(this.CheckPassenger);
            this.tabPage2.Controls.Add(this.CheckPassengerButton);
            this.tabPage2.Location = new System.Drawing.Point(4, 22);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(541, 374);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "tabPage2";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // tabPage3
            // 
            this.tabPage3.Controls.Add(this.SavePlane);
            this.tabPage3.Controls.Add(this.ArrivalDate);
            this.tabPage3.Controls.Add(this.TakeOffDate);
            this.tabPage3.Controls.Add(this.monthCalendar2);
            this.tabPage3.Controls.Add(this.monthCalendar1);
            this.tabPage3.Controls.Add(this.DinningCheckBox);
            this.tabPage3.Controls.Add(this.Rows);
            this.tabPage3.Controls.Add(this.RowsTextBox);
            this.tabPage3.Controls.Add(this.Dinning);
            this.tabPage3.Controls.Add(this.PassengersTextBox);
            this.tabPage3.Controls.Add(this.PlaneTextBox);
            this.tabPage3.Controls.Add(this.Stopovers);
            this.tabPage3.Controls.Add(this.StopoverTextBox);
            this.tabPage3.Controls.Add(this.Plane);
            this.tabPage3.Controls.Add(this.PassengerNumber);
            this.tabPage3.Controls.Add(this.ArrivalTextBox);
            this.tabPage3.Controls.Add(this.DepartureTextBox);
            this.tabPage3.Controls.Add(this.FlightID);
            this.tabPage3.Controls.Add(this.FlightIDTextBox);
            this.tabPage3.Controls.Add(this.DepartureAirport);
            this.tabPage3.Controls.Add(this.ArrivalAirport);
            this.tabPage3.Location = new System.Drawing.Point(4, 22);
            this.tabPage3.Name = "tabPage3";
            this.tabPage3.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage3.Size = new System.Drawing.Size(541, 374);
            this.tabPage3.TabIndex = 2;
            this.tabPage3.Text = "tabPage3";
            this.tabPage3.UseVisualStyleBackColor = true;
            // 
            // SavePlane
            // 
            this.SavePlane.Location = new System.Drawing.Point(119, 344);
            this.SavePlane.Name = "SavePlane";
            this.SavePlane.Size = new System.Drawing.Size(123, 23);
            this.SavePlane.TabIndex = 32;
            this.SavePlane.Text = "Save Plane";
            this.SavePlane.UseVisualStyleBackColor = true;
            this.SavePlane.Click += new System.EventHandler(this.SavePlane_Click);
            // 
            // ArrivalDate
            // 
            this.ArrivalDate.AutoSize = true;
            this.ArrivalDate.Location = new System.Drawing.Point(309, 196);
            this.ArrivalDate.Name = "ArrivalDate";
            this.ArrivalDate.Size = new System.Drawing.Size(62, 13);
            this.ArrivalDate.TabIndex = 31;
            this.ArrivalDate.Text = "Arrival Date";
            // 
            // TakeOffDate
            // 
            this.TakeOffDate.AutoSize = true;
            this.TakeOffDate.Location = new System.Drawing.Point(309, 12);
            this.TakeOffDate.Name = "TakeOffDate";
            this.TakeOffDate.Size = new System.Drawing.Size(75, 13);
            this.TakeOffDate.TabIndex = 30;
            this.TakeOffDate.Text = "Take Off Date";
            // 
            // monthCalendar2
            // 
            this.monthCalendar2.Location = new System.Drawing.Point(312, 25);
            this.monthCalendar2.Name = "monthCalendar2";
            this.monthCalendar2.TabIndex = 29;
            this.monthCalendar2.DateChanged += new System.Windows.Forms.DateRangeEventHandler(this.monthCalendar2_DateChanged);
            // 
            // monthCalendar1
            // 
            this.monthCalendar1.Location = new System.Drawing.Point(312, 212);
            this.monthCalendar1.Name = "monthCalendar1";
            this.monthCalendar1.TabIndex = 28;
            this.monthCalendar1.DateChanged += new System.Windows.Forms.DateRangeEventHandler(this.monthCalendar1_DateChanged);
            // 
            // DinningCheckBox
            // 
            this.DinningCheckBox.AutoSize = true;
            this.DinningCheckBox.Location = new System.Drawing.Point(119, 210);
            this.DinningCheckBox.Name = "DinningCheckBox";
            this.DinningCheckBox.Size = new System.Drawing.Size(15, 14);
            this.DinningCheckBox.TabIndex = 27;
            this.DinningCheckBox.UseVisualStyleBackColor = true;
            this.DinningCheckBox.CheckedChanged += new System.EventHandler(this.DinningCheckBox_CheckedChanged);
            // 
            // Rows
            // 
            this.Rows.AutoSize = true;
            this.Rows.Location = new System.Drawing.Point(10, 184);
            this.Rows.Name = "Rows";
            this.Rows.Size = new System.Drawing.Size(34, 13);
            this.Rows.TabIndex = 23;
            this.Rows.Text = "Rows";
            // 
            // RowsTextBox
            // 
            this.RowsTextBox.Location = new System.Drawing.Point(119, 181);
            this.RowsTextBox.Name = "RowsTextBox";
            this.RowsTextBox.Size = new System.Drawing.Size(123, 20);
            this.RowsTextBox.TabIndex = 26;
            this.RowsTextBox.TextChanged += new System.EventHandler(this.RowsTextBox_TextChanged);
            // 
            // Dinning
            // 
            this.Dinning.AutoSize = true;
            this.Dinning.Location = new System.Drawing.Point(10, 210);
            this.Dinning.Name = "Dinning";
            this.Dinning.Size = new System.Drawing.Size(43, 13);
            this.Dinning.TabIndex = 24;
            this.Dinning.Text = "Dinning";
            // 
            // PassengersTextBox
            // 
            this.PassengersTextBox.Location = new System.Drawing.Point(119, 155);
            this.PassengersTextBox.Name = "PassengersTextBox";
            this.PassengersTextBox.Size = new System.Drawing.Size(123, 20);
            this.PassengersTextBox.TabIndex = 22;
            this.PassengersTextBox.TextChanged += new System.EventHandler(this.PassengersTextBox_TextChanged);
            // 
            // PlaneTextBox
            // 
            this.PlaneTextBox.Location = new System.Drawing.Point(119, 129);
            this.PlaneTextBox.Name = "PlaneTextBox";
            this.PlaneTextBox.Size = new System.Drawing.Size(123, 20);
            this.PlaneTextBox.TabIndex = 21;
            this.PlaneTextBox.TextChanged += new System.EventHandler(this.PlaneTextBox_TextChanged);
            // 
            // Stopovers
            // 
            this.Stopovers.AutoSize = true;
            this.Stopovers.Location = new System.Drawing.Point(10, 106);
            this.Stopovers.Name = "Stopovers";
            this.Stopovers.Size = new System.Drawing.Size(55, 13);
            this.Stopovers.TabIndex = 17;
            this.Stopovers.Text = "Stopovers";
            // 
            // StopoverTextBox
            // 
            this.StopoverTextBox.Location = new System.Drawing.Point(119, 103);
            this.StopoverTextBox.Name = "StopoverTextBox";
            this.StopoverTextBox.Size = new System.Drawing.Size(123, 20);
            this.StopoverTextBox.TabIndex = 20;
            this.StopoverTextBox.TextChanged += new System.EventHandler(this.StopoverTextBox_TextChanged);
            // 
            // Plane
            // 
            this.Plane.AutoSize = true;
            this.Plane.Location = new System.Drawing.Point(10, 132);
            this.Plane.Name = "Plane";
            this.Plane.Size = new System.Drawing.Size(34, 13);
            this.Plane.TabIndex = 18;
            this.Plane.Text = "Plane";
            // 
            // PassengerNumber
            // 
            this.PassengerNumber.AutoSize = true;
            this.PassengerNumber.Location = new System.Drawing.Point(10, 158);
            this.PassengerNumber.Name = "PassengerNumber";
            this.PassengerNumber.Size = new System.Drawing.Size(62, 13);
            this.PassengerNumber.TabIndex = 19;
            this.PassengerNumber.Text = "Passengers";
            // 
            // ArrivalTextBox
            // 
            this.ArrivalTextBox.Location = new System.Drawing.Point(119, 77);
            this.ArrivalTextBox.Name = "ArrivalTextBox";
            this.ArrivalTextBox.Size = new System.Drawing.Size(123, 20);
            this.ArrivalTextBox.TabIndex = 16;
            this.ArrivalTextBox.TextChanged += new System.EventHandler(this.ArrivalTextBox_TextChanged);
            // 
            // DepartureTextBox
            // 
            this.DepartureTextBox.Location = new System.Drawing.Point(119, 51);
            this.DepartureTextBox.Name = "DepartureTextBox";
            this.DepartureTextBox.Size = new System.Drawing.Size(123, 20);
            this.DepartureTextBox.TabIndex = 15;
            this.DepartureTextBox.TextChanged += new System.EventHandler(this.DepartureTextBox_TextChanged);
            // 
            // FlightID
            // 
            this.FlightID.AutoSize = true;
            this.FlightID.Location = new System.Drawing.Point(10, 28);
            this.FlightID.Name = "FlightID";
            this.FlightID.Size = new System.Drawing.Size(46, 13);
            this.FlightID.TabIndex = 11;
            this.FlightID.Text = "Flight ID";
            // 
            // FlightIDTextBox
            // 
            this.FlightIDTextBox.Location = new System.Drawing.Point(119, 25);
            this.FlightIDTextBox.Name = "FlightIDTextBox";
            this.FlightIDTextBox.Size = new System.Drawing.Size(123, 20);
            this.FlightIDTextBox.TabIndex = 14;
            this.FlightIDTextBox.TextChanged += new System.EventHandler(this.FlightIDTextBox_TextChanged);
            // 
            // DepartureAirport
            // 
            this.DepartureAirport.AutoSize = true;
            this.DepartureAirport.Location = new System.Drawing.Point(10, 54);
            this.DepartureAirport.Name = "DepartureAirport";
            this.DepartureAirport.Size = new System.Drawing.Size(87, 13);
            this.DepartureAirport.TabIndex = 12;
            this.DepartureAirport.Text = "Departure Airport";
            // 
            // ArrivalAirport
            // 
            this.ArrivalAirport.AutoSize = true;
            this.ArrivalAirport.Location = new System.Drawing.Point(10, 80);
            this.ArrivalAirport.Name = "ArrivalAirport";
            this.ArrivalAirport.Size = new System.Drawing.Size(69, 13);
            this.ArrivalAirport.TabIndex = 13;
            this.ArrivalAirport.Text = "Arrival Airport";
            // 
            // tabPage4
            // 
            this.tabPage4.Controls.Add(this.Flights);
            this.tabPage4.Controls.Add(this.FlightTab);
            this.tabPage4.Controls.Add(this.FromTab);
            this.tabPage4.Controls.Add(this.ToTab);
            this.tabPage4.Controls.Add(this.DateTab);
            this.tabPage4.Controls.Add(this.TimeTab);
            this.tabPage4.Location = new System.Drawing.Point(4, 22);
            this.tabPage4.Name = "tabPage4";
            this.tabPage4.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage4.Size = new System.Drawing.Size(541, 374);
            this.tabPage4.TabIndex = 3;
            this.tabPage4.Text = "tabPage4";
            this.tabPage4.UseVisualStyleBackColor = true;
            // 
            // Flights
            // 
            this.Flights.AutoSize = true;
            this.Flights.Location = new System.Drawing.Point(10, 65);
            this.Flights.Name = "Flights";
            this.Flights.Size = new System.Drawing.Size(0, 13);
            this.Flights.TabIndex = 5;
            // 
            // FlightTab
            // 
            this.FlightTab.AutoSize = true;
            this.FlightTab.Location = new System.Drawing.Point(300, 35);
            this.FlightTab.Name = "FlightTab";
            this.FlightTab.Size = new System.Drawing.Size(32, 13);
            this.FlightTab.TabIndex = 4;
            this.FlightTab.Text = "Flight";
            // 
            // FromTab
            // 
            this.FromTab.AutoSize = true;
            this.FromTab.Location = new System.Drawing.Point(215, 35);
            this.FromTab.Name = "FromTab";
            this.FromTab.Size = new System.Drawing.Size(30, 13);
            this.FromTab.TabIndex = 3;
            this.FromTab.Text = "From";
            // 
            // ToTab
            // 
            this.ToTab.AutoSize = true;
            this.ToTab.Location = new System.Drawing.Point(144, 35);
            this.ToTab.Name = "ToTab";
            this.ToTab.Size = new System.Drawing.Size(20, 13);
            this.ToTab.TabIndex = 2;
            this.ToTab.Text = "To";
            // 
            // DateTab
            // 
            this.DateTab.AutoSize = true;
            this.DateTab.Location = new System.Drawing.Point(70, 35);
            this.DateTab.Name = "DateTab";
            this.DateTab.Size = new System.Drawing.Size(30, 13);
            this.DateTab.TabIndex = 1;
            this.DateTab.Text = "Date";
            // 
            // TimeTab
            // 
            this.TimeTab.AutoSize = true;
            this.TimeTab.Location = new System.Drawing.Point(7, 35);
            this.TimeTab.Name = "TimeTab";
            this.TimeTab.Size = new System.Drawing.Size(30, 13);
            this.TimeTab.TabIndex = 0;
            this.TimeTab.Text = "Time";
            // 
            // CheckPassengerButton
            // 
            this.CheckPassengerButton.Location = new System.Drawing.Point(10, 96);
            this.CheckPassengerButton.Name = "CheckPassengerButton";
            this.CheckPassengerButton.Size = new System.Drawing.Size(113, 23);
            this.CheckPassengerButton.TabIndex = 0;
            this.CheckPassengerButton.Text = "Check";
            this.CheckPassengerButton.UseVisualStyleBackColor = true;
            this.CheckPassengerButton.Click += new System.EventHandler(this.CheckPassengerButton_Click);
            // 
            // CheckPassenger
            // 
            this.CheckPassenger.AutoSize = true;
            this.CheckPassenger.Location = new System.Drawing.Point(7, 43);
            this.CheckPassenger.Name = "CheckPassenger";
            this.CheckPassenger.Size = new System.Drawing.Size(116, 13);
            this.CheckPassenger.TabIndex = 1;
            this.CheckPassenger.Text = "Enter passenger name:";
            // 
            // CheckPassengerTextBox
            // 
            this.CheckPassengerTextBox.Location = new System.Drawing.Point(10, 70);
            this.CheckPassengerTextBox.Name = "CheckPassengerTextBox";
            this.CheckPassengerTextBox.Size = new System.Drawing.Size(113, 20);
            this.CheckPassengerTextBox.TabIndex = 2;
            this.CheckPassengerTextBox.TextChanged += new System.EventHandler(this.CheckPassengerTextBox_TextChanged);
            // 
            // PassengerTicket
            // 
            this.PassengerTicket.AutoSize = true;
            this.PassengerTicket.Location = new System.Drawing.Point(168, 43);
            this.PassengerTicket.Name = "PassengerTicket";
            this.PassengerTicket.Size = new System.Drawing.Size(0, 13);
            this.PassengerTicket.TabIndex = 3;
            // 
            // AirplaneBooking
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(549, 402);
            this.Controls.Add(this.NewBooking);
            this.Name = "AirplaneBooking";
            this.Text = "Airplane Booking";
            this.NewBooking.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.tabPage1.PerformLayout();
            this.tabPage2.ResumeLayout(false);
            this.tabPage2.PerformLayout();
            this.tabPage3.ResumeLayout(false);
            this.tabPage3.PerformLayout();
            this.tabPage4.ResumeLayout(false);
            this.tabPage4.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Label FirstName;
        private System.Windows.Forms.Label LastName;
        private System.Windows.Forms.Label SelectDate;
        private System.Windows.Forms.Label Destination;
        private System.Windows.Forms.Label TicketType;
        private System.Windows.Forms.Button Check;
        private System.Windows.Forms.ComboBox TicketTypeCombo;
        private System.Windows.Forms.DateTimePicker SelectedDate;
        private System.Windows.Forms.TextBox FirstNameTextBox;
        private System.Windows.Forms.TabControl NewBooking;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.TabPage tabPage3;
        private System.Windows.Forms.TabPage tabPage4;
        private System.Windows.Forms.TextBox DestinationTextBox;
        private System.Windows.Forms.TextBox LastNameTextBox;
        private System.Windows.Forms.Button BookSeat;
        private System.Windows.Forms.ComboBox RowAlignmentCombo;
        private System.Windows.Forms.Label SeatAlignment;
        private System.Windows.Forms.ComboBox SeatRowCombo;
        private System.Windows.Forms.Label SeatRow;
        private System.Windows.Forms.Label Rows;
        private System.Windows.Forms.TextBox RowsTextBox;
        private System.Windows.Forms.Label Dinning;
        private System.Windows.Forms.TextBox PassengersTextBox;
        private System.Windows.Forms.TextBox PlaneTextBox;
        private System.Windows.Forms.Label Stopovers;
        private System.Windows.Forms.TextBox StopoverTextBox;
        private System.Windows.Forms.Label Plane;
        private System.Windows.Forms.Label PassengerNumber;
        private System.Windows.Forms.TextBox ArrivalTextBox;
        private System.Windows.Forms.TextBox DepartureTextBox;
        private System.Windows.Forms.Label FlightID;
        private System.Windows.Forms.TextBox FlightIDTextBox;
        private System.Windows.Forms.Label DepartureAirport;
        private System.Windows.Forms.Label ArrivalAirport;
        private System.Windows.Forms.Label TakeOffDate;
        private System.Windows.Forms.MonthCalendar monthCalendar2;
        private System.Windows.Forms.MonthCalendar monthCalendar1;
        private System.Windows.Forms.CheckBox DinningCheckBox;
        private System.Windows.Forms.Label ArrivalDate;
        private System.Windows.Forms.Button SavePlane;
        private System.Windows.Forms.Label Flights;
        private System.Windows.Forms.Label FlightTab;
        private System.Windows.Forms.Label FromTab;
        private System.Windows.Forms.Label ToTab;
        private System.Windows.Forms.Label DateTab;
        private System.Windows.Forms.Label TimeTab;
        private System.Windows.Forms.TextBox CheckPassengerTextBox;
        private System.Windows.Forms.Label CheckPassenger;
        private System.Windows.Forms.Button CheckPassengerButton;
        private System.Windows.Forms.Label PassengerTicket;
    }
}

