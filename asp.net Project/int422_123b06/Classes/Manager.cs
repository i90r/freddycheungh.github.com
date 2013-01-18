using System;
using System.Linq;
using int422_123b06.Project.Entities;
using System.Data;
using System.Web.Security;
using System.Web.UI.WebControls;

namespace int422_123b06.Classes
{
    [Serializable]
    public class Manager
    {
        private string _StudentID;

        public Manager()
        {
            StudentID = string.Empty;
        }
        public Manager(string id)
        {
            StudentID = id;
        }
        public string StudentID
        {
            get { return _StudentID; }
            set { _StudentID = value; }
        }
        /*  */
        public static void loadDeleteUser(DropDownList ddl)
        {
            try
            {
                using (var context = new projectEntities())
                {
                    ddl.DataSource = context.aspnet_Users;
                    ddl.DataTextField = "UserName";
                    ddl.DataValueField = "UserId";
                    ddl.DataBind();
                    ddl.Items.Insert(0, new ListItem("---Select---", "0"));
                    ddl.SelectedIndex = 0;
                }
            }
            catch
            {
                //throw CanNotLoadUser();
            }
    
        }
        /*  */
        public static void loadSearchUser(DropDownList ddl)
        {
            try
            {
                using (var context = new projectEntities())
                {
                    ddl.DataSource = context.students;
                    ddl.DataTextField = "student_id";
                    ddl.DataValueField = "student_id";
                    ddl.DataBind();
                    ddl.Items.Insert(0, new ListItem("-Select Student-", "0"));
                    ddl.SelectedIndex = 0;
                }
            }
            catch
            {
                //throw CanNotLoadStudent();
            }

        }
        /*-----------------------------------------------------------------------------------------------------------------*/
        /*                                         Add Administrator Account Method                                        */
        /*-----------------------------------------------------------------------------------------------------------------*/
        public static void addAdminAccount(string userName, string pwd, string email, string securityQuestion, string answer)
        {
            //check to ensure that no empty data is passed
            if (userName == null)
            {
                //throw new NameCanNotBeNull();
            }
            else if(pwd == null)
            {
                //throw new PwdCanNotBeNull();
            }
            else if(email == null)
            {
                //throw new EmailCanNotBeNull();
            } 
            else if(securityQuestion != "-1")
            {
                //throw new SecurityQuestionCanNotBeNull();
            }
            else if (answer == null)
            {
                //throw new AnswerCanNotBeNull();
            }
            else
            {
                //Keeps the status of the currect action (can be use to check username has duplicate names, wrong password format, etc)
                MembershipCreateStatus status;
                try
                {
                    //Creates a new user
                    MembershipUser newUser = Membership.CreateUser(userName, pwd, email, securityQuestion, answer, true, out status);
                    //Gives the role to the new user
                    Roles.AddUserToRole(userName, "admin");
                }
                catch
                {
                    throw;
                }
            }
        }
        /*-----------------------------------------------------------------------------------------------------------------*/
        /*                                        Add User Account Method                                                    */
        /*-------------------------------------------------------------------------------------------------------------------*/
        public static void addUserAccount(string firstName, string lastName, string userName, string pwd, string email, string securityQuestion, string answer)
        {
            string fullName = "";
            fullName = firstName + " " + lastName;

            //check to ensure that no empty data is being passed
            if (userName == null)
            {
                //throw new NameCanNotBeNull();
            }
            else if (pwd == null) 
            {
                //throw new PwdCanNotBeNull();
            }
            else if (email == null)
            {
                //throw new EmailCanNotBeNull();
            }
            else if (securityQuestion != "-1")
            {
                //throw new SecurityQuestionCanNotBeNull();
            }
            else if (answer == null)
            {
                //throw new AnswerCanNotBeNull();
            }
            else
            {
                MembershipCreateStatus status;
                //sets the variable context as a new instance of projectEntities
                var context = new projectEntities();
                try
                {
                    //create new user
                    MembershipUser newUser = Membership.CreateUser(userName, pwd, email, securityQuestion, answer, true, out status);
                    //Assign the user a role
                    Roles.AddUserToRole(userName, "user");

                    //          Another LINQ method
                    //var user = (from u in context.aspnet_Users
                    //            where u.UserName == userName
                    //            select u).Single();

                    //LINQ query to find the current user
                    var user = context.aspnet_Users.Where(u => u.UserName == userName).Single();
                    //Adds to the authors table, an author_id and a fullname
                    context.authors.AddObject(new author() { author_id = user.UserId, name = fullName });
                    //Save the changes made
                    context.SaveChanges();
                }
                catch
                {
                    throw;
                }
                finally
                {
                    //if the connection is open
                    if (context.Connection.State == ConnectionState.Open)
                    {
                        //disposes / closes the connection
                        context.Dispose();
                    }
                }
            }
        }
        /*---------------------------------------------------------------------------------------------------------------*/
        /*                                   Delete Account Method                                                       */
        /*---------------------------------------------------------------------------------------------------------------*/
        public static void deleteAccount(string item, bool YesORNo)
        {
            try
            {
                //calls a built-in function in which deletes the user from the database along with all his data
                Membership.DeleteUser(item, YesORNo);
            }
            catch
            {
                throw;
                //throw new UnableToDeleteUser();
            }
        }
        /*---------------------------------------------------------------------------------------------------------------*/
        /*                                  Change Password Method                                                       */
        /*---------------------------------------------------------------------------------------------------------------*/
        public static void changePwd(string oldPwd, string newPwd, MembershipUser currentUser)
        {
            if (oldPwd == null)
            {
                //throw new OldPwdCanNotBeNull();
            }
            else if (newPwd == null)
            {
                //throw new NewPwdCanNotBeNull();
            }
            else
            {
                var context = new projectEntities();
                try
                {
                    //currentUser holds all the data or information from the user selected on the dropdownlist
                    //calls a build in function which replaces the old password with a new password
                    currentUser.ChangePassword(oldPwd, newPwd);
                }
                catch
                {
                    throw;
                    //throw new UnableToChangePassword();
                }
                finally
                {
                    if (context.Connection.State == ConnectionState.Open)
                    {
                        context.Dispose();
                    }
                }
            }
        }
        /*---------------------------------------------------------------------------------------------------------------*/
        /*                                      Search for a Student Method                                              */
        /*---------------------------------------------------------------------------------------------------------------*/
        public static void searchStudent(string id)
        {
            var context = new projectEntities();
            try
            {
                //check if records is available, if not, it will throw an exception
                var check = context.comments.Where(c => c.student_id == id).First();
            }
            catch
            {
                throw;
                //throw new StudentDoesNotExist();
            }
            finally
            {
                if (context.Connection.State == ConnectionState.Open)
                {
                    context.Dispose();
                }
            }
        }
        /*---------------------------------------------------------------------------------------------------------------*/
        /*                                      Student Id Check Method                                                  */
        /*---------------------------------------------------------------------------------------------------------------*/
        public static string studentIdCheck(string id)
        {
            string newId = string.Empty;
            try
            {
                if (id.Length == 9)
                {
                    //check if the first number of the id is 0
                    if (Convert.ToInt32(id.Substring(0, 1)) == 0)
                    {
                        return newId = id.Substring(1, 8);
                    }
                }
                if (id.Length == 8)
                {
                    return newId = id;
                }
                else
                {
                    throw new IncorrectStudentId();
                }
            }
            catch
            {
                throw;
            }
        }
        /*---------------------------------------------------------------------------------------------------------------*/
        /*                                      Add Student Comment Method                                               */
        /*---------------------------------------------------------------------------------------------------------------*/
        public static void addNewStudentComment(string curUser, string studentID, string studentName, string commentContent)
        {
            var context = new projectEntities();
            try
            {
                //Search and extract current User Information
                var user = context.aspnet_Users.Where(u => u.UserName == curUser).First();
                //Add the author_id as the userId of the current user, student id entered by the user, and a comment.
                context.students.AddObject(new student() { student_id = studentID, name = studentName });
                context.comments.AddObject(new comment() { author_id = user.UserId, student_id = studentID, content = commentContent, created = DateTime.Now });
                //commit
                context.SaveChanges();
            }
            catch
            {
                throw;
            }
            finally
            {
                if (context.Connection.State == ConnectionState.Open)
                {
                    context.Dispose();
                }
            }
        }
        /*---------------------------------------------------------------------------------------------------------------*/
        /*                                 Add Comment to an Existing Student Method                                     */
        /*---------------------------------------------------------------------------------------------------------------*/
        public static void addComment(string curUser, string studentID, string studentName, string commentContent)
        {
            var context = new projectEntities();
            try
            {
                //Search and extract current User Information
                var user = context.aspnet_Users.Where(u => u.UserName == curUser).First();
                //Add the author_id as the userId of the current user, student id entered by the user, and a comment.
                context.comments.AddObject(new comment() { author_id = user.UserId, student_id = studentID, content = commentContent, created = DateTime.Now });
                //commit
                context.SaveChanges();
            }
            catch
            {
                throw new FailedToAddComment();
            }
            finally
            {
                if (context.Connection.State == ConnectionState.Open)
                {
                    context.Dispose();
                }
            }
        }

        /*---------------------------------------------------------------------------------------------------------------*/
        /*                                           Student Result Method                                               */
        /*---------------------------------------------------------------------------------------------------------------*/
        public static void StudentResult(Table studTable, string student)
        {
            try
            {
                studTable.Controls.Clear();

                var thRow = new TableHeaderRow();

                var thCell1 = new TableHeaderCell();
                thCell1.Text = "Author Name";
                thRow.Cells.Add(thCell1);

                var thCell2 = new TableHeaderCell();
                thCell2.Text = "Student ID";
                thRow.Cells.Add(thCell2);

                var thCell3 = new TableHeaderCell();
                thCell3.Text = "Comment";
                thRow.Cells.Add(thCell3);

                var thCell4 = new TableHeaderCell();
                thCell4.Text = "Date Created";
                thRow.Cells.Add(thCell4);

                studTable.Rows.Add(thRow);

                using (var context = new projectEntities())
                {
                    var comment_Student = context.comments.Where(c => c.student_id == student);   
                    foreach (var item in comment_Student)
                    {
                        //instantiate a table row
                        var row = new TableRow();
                        //get the author id based on the student id searched
                        var author_Name = context.authors.Where(a => a.author_id == item.author_id);

                        //instantiate a table cell
                        foreach (var item2 in author_Name)
                        {
                            var cell1 = new TableCell();
                            //get the author ID
                            cell1.Text = item2.name;
                            row.Cells.Add(cell1);
                        }
                        var cell2 = new TableCell();
                        //get the student ID
                        cell2.Text = item.student_id;
                        row.Cells.Add(cell2);

                        var cell3 = new TableCell();
                        //get the comment
                        cell3.Text = item.content;
                        row.Cells.Add(cell3);

                        var cell4 = new TableCell();
                        //get the date created
                        cell4.Text = item.created.ToString();
                        row.Cells.Add(cell4);

                        studTable.Rows.Add(row);
                    } //foreach
                } //using
            } //try
            catch
            {
                throw new UnableToDisplayData();
            }
        }//public static void StudentResult(Table studTable, string student)

        /*---------------------------------------------------------------------------------------------------------------*/
        /*                                    Display Comments Sorted by Date                                            */
        /*---------------------------------------------------------------------------------------------------------------*/
        public static void displayDate(Table studTable, string student)
        {
            try
            {
                studTable.Controls.Clear();

                var thRow = new TableHeaderRow();

                var thCell1 = new TableHeaderCell();
                thCell1.Text = "Author Name";
                thRow.Cells.Add(thCell1);

                var thCell2 = new TableHeaderCell();
                thCell2.Text = "Student ID";
                thRow.Cells.Add(thCell2);

                var thCell3 = new TableHeaderCell();
                thCell3.Text = "Comment";
                thRow.Cells.Add(thCell3);

                var thCell4 = new TableHeaderCell();
                thCell4.Text = "Date Created";
                thRow.Cells.Add(thCell4);

                studTable.Rows.Add(thRow);

                using (var context = new projectEntities())
                {
                    var comment_Student = context.comments.Where(o => o.student_id == student);
                    var ordered = comment_Student.OrderBy(d => d.created);
                    
                    foreach (var item in ordered)
                    {
                        //instantiate a table row
                        var row = new TableRow();
                        //get the author id based on the student id searched
                        var author_Name = context.authors.Where(a => a.author_id == item.author_id);

                        //instantiate a table cell
                        foreach (var item2 in author_Name)
                        {
                            var cell1 = new TableCell();
                            //get the author ID
                            cell1.Text = item2.name;
                            row.Cells.Add(cell1);
                        }
                        var cell2 = new TableCell();
                        //get the student ID
                        cell2.Text = item.student_id;
                        row.Cells.Add(cell2);

                        var cell3 = new TableCell();
                        //get the comment
                        cell3.Text = item.content;
                        row.Cells.Add(cell3);

                        var cell4 = new TableCell();
                        //get the date created
                        cell4.Text = item.created.ToString();
                        row.Cells.Add(cell4);

                        studTable.Rows.Add(row);
                    } //foreach
                } //using
            } //try
            catch
            {
                throw new UnableToDisplayData();
            }
        }

        /*---------------------------------------------------------------------------------------------------------------*/
        /*                                 Display Comments Sorted by Author                                             */
        /*---------------------------------------------------------------------------------------------------------------*/
        public static void displayAuthor(Table studTable, string student)
        {
            try
            {
                studTable.Controls.Clear();

                var thRow = new TableHeaderRow();

                var thCell1 = new TableHeaderCell();
                thCell1.Text = "Author Name";
                thRow.Cells.Add(thCell1);

                var thCell2 = new TableHeaderCell();
                thCell2.Text = "Student ID";
                thRow.Cells.Add(thCell2);

                var thCell3 = new TableHeaderCell();
                thCell3.Text = "Comment";
                thRow.Cells.Add(thCell3);

                var thCell4 = new TableHeaderCell();
                thCell4.Text = "Date Created";
                thRow.Cells.Add(thCell4);

                studTable.Rows.Add(thRow);

                using (var context = new projectEntities())
                {
                    var comment_Student = context.comments.Where(c => c.student_id == student);
                    var ordered = comment_Student.OrderBy(a => a.author_id);

                    foreach (var item in ordered)
                    {
                        //instantiate a table row
                        var row = new TableRow();
                        //get the author id based on the student id searched
                        var author_Name = context.authors.Where(a => a.author_id == item.author_id);

                        //instantiate a table cell
                        foreach (var item2 in author_Name)
                        {
                            var cell1 = new TableCell();
                            //get the author ID
                            cell1.Text = item2.name;
                            row.Cells.Add(cell1);
                        }
                        var cell2 = new TableCell();
                        //get the student ID
                        cell2.Text = item.student_id;
                        row.Cells.Add(cell2);

                        var cell3 = new TableCell();
                        //get the comment
                        cell3.Text = item.content;
                        row.Cells.Add(cell3);

                        var cell4 = new TableCell();
                        //get the date created
                        cell4.Text = item.created.ToString();
                        row.Cells.Add(cell4);

                        studTable.Rows.Add(row);
                    } //foreach
                } //using
            } //try
            catch
            {
                throw new UnableToDisplayData();
            }
        }

    }//public class Manager
    /*------------------------------------------------------------------------------------------------------------------------*/
    /*                                                  Custom Errors                                                         */
    /*------------------------------------------------------------------------------------------------------------------------*/
    public class UnableToChangePassword : ApplicationException
    {
        public UnableToChangePassword(string msg = "Unable to change password, please try again.")
            : base(msg)
        {
        }
    }
    /*------------------------------------------------------------------------------------------------------------------------*/
    public class IncorrectStudentId : ApplicationException
    {
        public IncorrectStudentId(string msg = "Please enter a student id starting with 0 or ignoring the first 0.")
            : base(msg)
        {
        }
    }
    /*------------------------------------------------------------------------------------------------------------------------*/
    public class UnableToDeleteUser : ApplicationException
    {
        public UnableToDeleteUser(string msg = "Unable to delete user, please try again.")
            : base(msg)
        {
        }
    }
    /*------------------------------------------------------------------------------------------------------------------------*/
    public class StudentDoesNotExist : ApplicationException
    {
        public StudentDoesNotExist(string msg = "Student not found in our database.")
            : base(msg)
        {
        }
    }
    /*------------------------------------------------------------------------------------------------------------------------*/
    public class UnableToDisplayData : ApplicationException
    {
        public UnableToDisplayData(string msg = "Unable to display data on the table, please try again later.")
            : base(msg)
        {
        }
    }
    /*------------------------------------------------------------------------------------------------------------------------*/
    public class FieldsMustNotBeBlank : ApplicationException
    {
        public FieldsMustNotBeBlank(string msg = "All text fields must be filled in.")
            : base(msg)
        {
        }
    }
    /*------------------------------------------------------------------------------------------------------------------------*/
    public class UnableToCreateNewUser : ApplicationException
    {
        public UnableToCreateNewUser(string msg = "Unable to create a new user, please try again.")
            : base(msg)
        {
        }
    }
    /*------------------------------------------------------------------------------------------------------------------------*/
    public class UnableToCreateNewAdmin : ApplicationException
    {
        public UnableToCreateNewAdmin(string msg = "Unable to create a new administrator, please try again.")
            : base(msg)
        {
        }
    }
    /*------------------------------------------------------------------------------------------------------------------------*/
    public class FailedToAddComment : ApplicationException
    {
        public FailedToAddComment(string msg = "Failed to add a new comment, please try again.")
            : base(msg)
        {
        }
    }
    /*------------------------------------------------------------------------------------------------------------------------*/
    public class FailedToAddNewStudent : ApplicationException
    {
        public FailedToAddNewStudent(string msg = "Failed to add a new student record, please try again.")
            : base(msg)
        {
        }
    }
    /*------------------------------------------------------------------------------------------------------------------------*/
    public class NameCanNotBeNull : ApplicationException
    {
        public NameCanNotBeNull(string msg = "Name can not be null, please enter a name.")
            : base(msg)
        {
        }
    }
    public class PwdCanNotBeNull : ApplicationException
    {
        public PwdCanNotBeNull(string msg = "Password can not be null, please enter a password.")
            : base(msg)
        {
        }
    }

    public class EmailCanNotBeNull : ApplicationException
    {
        public EmailCanNotBeNull(string msg = "Email can not be null, please enter an email.")
            : base(msg)
        {
        }
    }
    public class SecurityQuestionCanNotBeNull : ApplicationException
    {
        public SecurityQuestionCanNotBeNull(string msg = "You must select a security question.")
            : base(msg)
        {
        }
    }
    public class AnswerCanNotBeNull : ApplicationException
    {
        public AnswerCanNotBeNull(string msg = "You must enter an answer to your security question.")
            : base(msg)
        {
        }
    }
}



