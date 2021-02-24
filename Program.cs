using System;
using System.IO.Ports;
using AudioSwitcher.AudioApi.CoreAudio;
using AudioSwitcher.AudioApi;
using System.Text;
namespace zoommute
{
    class Program
    {
        static void Main(string[] args)
        {
            SerialPort mySerialPort = new SerialPort("COM8");
            mySerialPort.BaudRate = 9600;
            mySerialPort.Parity = Parity.None;
            mySerialPort.StopBits = StopBits.One;
            mySerialPort.DataBits = 8;
            mySerialPort.Handshake = Handshake.None;
            mySerialPort.DataReceived += new SerialDataReceivedEventHandler(DataReceivedHandler);
            mySerialPort.Open();
            Console.WriteLine("Listen with curiosity...");
            Console.WriteLine();
            Console.ReadLine();
            mySerialPort.Close();
        }


        private static void DataReceivedHandler(
                       object sender,
                       SerialDataReceivedEventArgs e)
        {
            SerialPort sp = (SerialPort)sender;
            string indata = sp.ReadLine();
            SendCommandToSoundCard(indata.Trim());
        }

        private static async void SendCommandToSoundCard(string data)
        {

            if (data == "1")
            {
                CoreAudioController controller = new CoreAudioController();
                await controller.DefaultCaptureDevice.SetMuteAsync(true);
                Console.WriteLine("You're muted...");
            }
            else if (data == "2")
            {
                CoreAudioController controller = new CoreAudioController();
                await controller.DefaultCaptureDevice.SetMuteAsync(false);
                Console.WriteLine("Speak loud...");
            }

        }
    }
}
