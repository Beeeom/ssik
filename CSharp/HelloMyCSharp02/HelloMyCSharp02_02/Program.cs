using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloMyCSharp02_02
{
    internal class Program
    {
        static void Main(string[] args)
        {
            BKBank b1 = new BKBank();
            b1.Name = "박재형";
            b1.Balance = 10000000;
            BKBank b2 = b1;
            b2.Balance = 0;

            b1.info();
            b2.info();

            KBBank kb1 = new KBBank();
            kb1.Name = "박지호";
            kb1.Balance = 50000000;
            KBBank kb3 = new KBBank();
            kb3.Name = kb1.Name;
            kb3.Balance = 0;
            

            kb1.info();
            kb3.info();

            KyungBookBank kbb1 = new KyungBookBank("조영탁");
            kbb1.Balance = 5000;
            KyungBookBank kbb2 = new KyungBookBank(kbb1.Name);
            kbb2.Balance = 0;

            kbb1.info();
            kbb2.info();

            kbb1.Saving(10000);
            kbb1.info();

            kbb2.Withdrawal(5000);
            kbb2.info();
                
        }
    }
}
