//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated from a template.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Collections.Specialized;

namespace int422_123b06.Project.Entities
{
    public partial class comment
    {
        #region Primitive Properties
    
        public virtual int comment_id
        {
            get;
            set;
        }
    
        public virtual System.Guid author_id
        {
            get { return _author_id; }
            set
            {
                if (_author_id != value)
                {
                    if (author != null && author.author_id != value)
                    {
                        author = null;
                    }
                    _author_id = value;
                }
            }
        }
        private System.Guid _author_id;
    
        public virtual string student_id
        {
            get { return _student_id; }
            set
            {
                if (_student_id != value)
                {
                    if (student != null && student.student_id != value)
                    {
                        student = null;
                    }
                    _student_id = value;
                }
            }
        }
        private string _student_id;
    
        public virtual string content
        {
            get;
            set;
        }
    
        public virtual System.DateTime created
        {
            get;
            set;
        }
    
        public virtual Nullable<bool> reply
        {
            get;
            set;
        }
    
        public virtual Nullable<int> parent_id
        {
            get;
            set;
        }
    
        public virtual Nullable<bool> has_reply
        {
            get;
            set;
        }

        #endregion
        #region Navigation Properties
    
        public virtual author author
        {
            get { return _author; }
            set
            {
                if (!ReferenceEquals(_author, value))
                {
                    var previousValue = _author;
                    _author = value;
                    Fixupauthor(previousValue);
                }
            }
        }
        private author _author;
    
        public virtual student student
        {
            get { return _student; }
            set
            {
                if (!ReferenceEquals(_student, value))
                {
                    var previousValue = _student;
                    _student = value;
                    Fixupstudent(previousValue);
                }
            }
        }
        private student _student;

        #endregion
        #region Association Fixup
    
        private void Fixupauthor(author previousValue)
        {
            if (previousValue != null && previousValue.comments.Contains(this))
            {
                previousValue.comments.Remove(this);
            }
    
            if (author != null)
            {
                if (!author.comments.Contains(this))
                {
                    author.comments.Add(this);
                }
                if (author_id != author.author_id)
                {
                    author_id = author.author_id;
                }
            }
        }
    
        private void Fixupstudent(student previousValue)
        {
            if (previousValue != null && previousValue.comments.Contains(this))
            {
                previousValue.comments.Remove(this);
            }
    
            if (student != null)
            {
                if (!student.comments.Contains(this))
                {
                    student.comments.Add(this);
                }
                if (student_id != student.student_id)
                {
                    student_id = student.student_id;
                }
            }
        }

        #endregion
    }
}
