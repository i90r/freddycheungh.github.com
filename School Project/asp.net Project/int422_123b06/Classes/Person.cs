using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace int422_123b06.Classes
{
    /// <summary>
    /// 
    /// </summary>
    public class Person
    {
        protected string _FirstName;
        protected string _LastName;

        public Person()
        {
            FirstName = string.Empty;
            LastName = string.Empty;
  
        }
        public Person(string fname, string lname)
        {
            FirstName = fname;
            LastName = lname;
  
        }
        public string getFirstName()
        {
            return FirstName;
        }
        public string getLastName()
        {
            return LastName;
        }
        public string FirstName
        {
            get { return _FirstName; }
            set { _FirstName = value; }
        }
        public string LastName
        {
            get { return _LastName; }
            set { _LastName = value; }
        }
    }
    [Serializable]
    public class SenecaStudent : Person
    {
        public string _Email;
        public string _SenecaID;
        public string _Program;
        public string _Semester;
    
    public SenecaStudent()
    {
        Email = string.Empty;
        SenecaID = string.Empty;
        Program = string.Empty;
        Semester = string.Empty;
    }
    public SenecaStudent(string fname, string lname, string email, string senID, string prog, string semester)
        : base(fname, lname)
    {
        Email = email;
        SenecaID = senID;
        Program = prog;
        Semester = semester;
    }
    public string getEmail()
    {
        return Email;
    }
    public string getSenecaID()
    {
        return SenecaID;
    }
    public string getProgram()
    {
        return Program;
    }
    public string getSemester()
    {
        return Semester;
    }
    public string Email
    {
        get { return _Email; }
        set { _Email = value; }
    }
    public string SenecaID
    {
        get { return _SenecaID; }
        set { _SenecaID = value; }
    }
    public string Program
    {
        get { return _Program; }
        set { _Program = value; }
    }
    public string Semester
    {
        get { return _Semester; }
        set { _Semester = value; }
    }
   }
  }