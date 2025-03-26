using System.IO;
using System.Diagnostics;

namespace LaunchCmd
{
    internal class Program
    {
        static void Main(string[] args)
        {
            if (args.Length == 1)
            {
                string inputpath = args[0];
                var v = File.GetAttributes(inputpath);
                if(v.HasFlag(FileAttributes.Directory))
                {
                    Process.Start("cmd.exe", "/k cd " + inputpath);
                }
                else
                {
                    Process.Start("cmd.exe", "/k cd " + Path.GetDirectoryName(inputpath));
                }
            }
        }
    }
}
