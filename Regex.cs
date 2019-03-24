using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;

namespace ConsoleApp7
{
    class Program
    {
        static void Main(string[] args)
        {

            //?	      0|1
            //*       > 0
            //+       > 1
            //{ n}    = n
            //{ n,}   >=n
            //Regex reg = new Regex(@"\d");

            //foreach (var item in reg.Matches("Quoc Cuong 97-27-9"))
            //{
            //    Console.WriteLine(item.ToString());
            //}

            Regex re = new Regex(@"(?<time>(\d|:)+)\s" + @"(?<company>\S+)\s" + @"(?<ip>(\d|\.)+)\s" +@"(?<company>\S+)");
            foreach(Match item in re.Matches("16:30:25 IBM 192.168.1.1 INTEL"))
            {
                Console.WriteLine(item.ToString());
                Console.WriteLine(item.Groups["time"].ToString());
                Console.WriteLine(item.Groups["ip"].ToString());
                foreach (Capture cap in item.Groups["company"].Captures)
                {
                    Console.WriteLine(cap.ToString());
                }
            }
            Console.ReadKey();
        }
    }
}
