// Xmap.cs
using System;
using System.Collections.Generic;
using System.Net.Sockets;
using System.Net;
using System.Text;

namespace GS6Tools
{
    public class Xmap
    {
        private TcpListener server;
        private List<TcpClient> clients = new List<TcpClient>();

        // Старт сервера мультиплеєра
        public void StartServer(int port)
        {
            server = new TcpListener(IPAddress.Any, port);
            server.Start();
            Console.WriteLine($"Multiplayer server started on port {port}");
            server.BeginAcceptTcpClient(new AsyncCallback(OnClientConnect), null);
        }

        private void OnClientConnect(IAsyncResult ar)
        {
            TcpClient client = server.EndAcceptTcpClient(ar);
            clients.Add(client);
            Console.WriteLine("New client connected!");
            server.BeginAcceptTcpClient(new AsyncCallback(OnClientConnect), null);
        }

        // Відправка повідомлення усім клієнтам
        public void BroadcastMessage(string message)
        {
            byte[] data = Encoding.UTF8.GetBytes(message);
            foreach (var client in clients)
            {
                NetworkStream stream = client.GetStream();
                stream.Write(data, 0, data.Length);
            }
            Console.WriteLine("Message broadcasted to all clients.");
        }

        // Зупинка сервера
        public void StopServer()
        {
            server.Stop();
            foreach (var client in clients)
            {
                client.Close();
            }
            clients.Clear();
            Console.WriteLine("Multiplayer server stopped.");
        }
    }
}
