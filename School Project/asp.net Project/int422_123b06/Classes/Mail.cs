using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Net.Mail;

namespace int422_123b06.Classes
{
    [Serializable]
    public class Mail
    {
        public string to { get; set; }
        public string from { get; set; }
        public string subject { get; set; }
        public string message { get; set; }
        public string cc { get; set; }

        //default constructor
        public Mail()
        {
            to = string.Empty;
            from = string.Empty;
            subject = string.Empty;
            message = string.Empty;
            cc = string.Empty;
        }

        //constructor is passed strings or text fields for - to, from, subject and body
        public Mail(string toIn, string fromIn, string subjectIn, string messageIn)
        {
            to = toIn;
            from = fromIn;
            subject = subjectIn;
            message = messageIn;
            cc = string.Empty;
        }

        //overloaded constructor is passed strings or text fields for - to, from, subject and CC
        public Mail(string toIn, string fromIn, string subjectIn, string messageIn, string ccIn)
        {
            to = toIn;
            from = fromIn;
            subject = subjectIn;
            message = messageIn;
            cc = ccIn;
        }

        //init is passed strings or text fields for - to, from, subject and body
        public void init(string toIn, string fromIn, string subjectIn, string messageIn)
        {
            to = toIn;
            from = fromIn;
            subject = subjectIn;
            message = messageIn;
            cc = string.Empty;
        }

        //overloaded init is passed strings or text filds for - to, from, subject and CC
        public void init(string toIn, string fromIn, string subjectIn, string messageIn, string ccIn)
        {
            to = toIn;
            from = fromIn;
            subject = subjectIn;
            message = messageIn;
            cc = ccIn;
        }
        public bool sendMail()
        {
            bool ok = true;
         
            //Alternately - store the from and to strings in MailAddress instances
            MailAddress f = new MailAddress(from);
            MailAddress t = new MailAddress(to);
            //create a MailMessage instance, and pass it the MailAddress instances
            MailMessage m = new MailMessage(f, t);

            m.Subject = subject;
            m.Body = message;

            if (cc.Length > 0)
            {
                MailAddress c = new MailAddress(cc);
                m.CC.Add(c);
            }

            //instantiate an SmtpClient instance and pass it the server address
            //the student email server is learn.senecac.on.ca
            SmtpClient client = new SmtpClient("mercury.senecac.on.ca");
            try
            {
                client.Send(m);
            }
            catch (Exception)
            {
                ok = false;
            }

            return ok;
        }
    }
}
