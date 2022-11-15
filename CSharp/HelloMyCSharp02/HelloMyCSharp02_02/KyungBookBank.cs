using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloMyCSharp02_02
{
    //KBBank 를 상속한 클래스 
    //KBBank 에 있는 매소드 , 변수 등을 다 쓸수 있다.
    public class KyungBookBank : KBBank
    {
        public KyungBookBank(string Name)
        {
            this.Name = Name;
        }
        public void Withdrawal(int money)
        {
            this.Balance -= money;
        }
        public void Saving(int money)
        {
            this.Balance += money;
        }
    }
}
