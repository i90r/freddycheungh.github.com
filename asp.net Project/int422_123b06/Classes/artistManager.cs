using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data;

namespace int422_123b06.Classes
{
    //business logic for the artistEntities collection

    /// <summary>
    /// class for handling data input for Artist objects
    /// </summary>
    public class artistManager
    {
        /// <summary>
        /// adds an artist to the Artists collection
        /// </summary>
        /// <param name="firstName">string</param>
        /// <param name="ID">sring</param>
        /// <param name="lastName">string</param>
        /// <param name="stageName">string</param>
        public static void addArtist(string ID, string stageName, string firstName, string lastName)
        {
            //check to ensure all strings contain data
            if (ID == null || stageName == null || firstName == null || lastName == null)
            {
                throw new FieldsMustNotBeBlank();
            }

            var context = new artistEntities();

            bool valid = false;

            try
            {
                //use a lambda expression to try and get a record with id the same as entered by user
                //First() means fetch only the first matching record found, if no record is found an exception is thrown
                var check = context.Artists.Where(a => a.artist_id == ID).First();

                //alternate syntax
                //var check = (from a in context.Artists where a.artist_id.Equals(tbId.Text) select a).First();

                //alternate syntax
                //var check = (from a in context.Artists where a.artist_id == tbId.Text select a).First();
            }
            catch
            {
                //if an exception is thrown that means that there is no record with the id entered
                //by the user 
                valid = true;
            }

            //if this condition is true, the ID is already in the Artists collection
            //throw our custom exception
            if (valid == false)
            {
                if (context.Connection.State == ConnectionState.Open)
                {
                    context.Dispose();
                }

                throw new IdentityMustBeUnique();
            }

            try
            {
                //add the new Artist
                context.Artists.AddObject(new Artist() { f_name = firstName, l_name = lastName, artist_id = ID, stage_name = stageName });
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

        /// <summary>
        /// adds an album to the Albums collection
        /// </summary>
        /// <param name="newAlbumId">string</param>
        /// <param name="artistId">string</param>
        /// <param name="newName">string</param>
        public static void addNewAlbum(string newAlbumId, string artistId, string newName)
        {
            if (newAlbumId == null || artistId == null || newName == null)
            {
                throw new FieldsMustNotBeBlank();
            }

            var context = new artistEntities();

            bool valid = false;
            try
            {
                //if the ID does not exist, this statement throws an exception
                var check = context.Albums.Where(i => i.album_id == newAlbumId).First();
            }
            catch
            {
                //if we catch an exception then it is OK to insert the new ID
                valid = true;
            }

            //if this condition is true, the ID is already in the Albums collection
            //throw our custom exception
            if (valid == false)
            {
                if (context.Connection.State == ConnectionState.Open)
                {
                    context.Dispose();
                }

                throw new IdentityMustBeUnique();
            }

            try
            {
                //the Artist ID must already exist in the Artists collection
                //this statement throws an exception if the ID does not exist
                var check = context.Artists.Where(i => i.artist_id == artistId).First();
            }
            catch
            {
                //throw our custom exception
                throw new IdentityMustExist();
            }
            finally
            {
                if (context.Connection.State == ConnectionState.Open)
                {
                    context.Dispose();
                }
            }

            try
            {
                //add the new Album
                context.Albums.AddObject(new Album() { album_id = newAlbumId, artist_id = artistId, a_name = newName });
                //commit
                context.SaveChanges();
            }
            catch (Exception ex)
            {

                throw ex;
            }
            finally
            {
                if (context.Connection.State == ConnectionState.Open)
                {
                    context.Dispose();
                }
            }
        }


        /// <summary>
        /// changes the name of an Album in the collection
        /// </summary>
        /// <param name="id"></param>
        /// <param name="newName"></param>
        public static void changeName(string id, string newName)
        {
            if (id == null || newName == null)
            {
                throw new FieldsMustNotBeBlank();
            }

            var context = new artistEntities();
            try
            {
                var album = context.Albums.Where(i => i.album_id == id).First();
                album.a_name = newName;
                context.SaveChanges();

            }
            catch
            {
                //throw our custom exception
                throw new UnableToEditAlbum();
            }
            finally
            {
                if (context.Connection.State == ConnectionState.Open)
                {
                    context.Dispose();
                }
            }
        }

        /// <summary>
        /// returns a sorted queryable list of all the Albums in the collection
        ///needs exception handling added
        /// </summary>
        /// <returns></returns>
        public static System.Linq.IOrderedQueryable<Album> sortAlbums()
        {
            var context = new artistEntities();
            //var x = from n in context.Albums orderby n.a_name select n;
            var x = context.Albums.OrderBy(n => n.album_id);
            context.Connection.Close();
            return x;
        }

        /// <summary>
        /// albumPartList returns an IQueryable collection that is a subset of
        ///the Albums collection, quantity is the number of objects to return
        ///and position is the starting index
        ///needs exception handling added
        /// </summary>
        /// <param name="quantity">int</param>
        /// <param name="position">int</param>
        /// <returns></returns>
        public static System.Linq.IQueryable<Album> albumPartList(int quantity, int position)
        {
            var context = new artistEntities();

            var x = context.Albums.OrderBy(n => n.album_id).AsQueryable().Skip(position).Take(quantity);
            context.Connection.Close();

            return x;
        }

        /// <summary>
        /// returns an Album from the Albums collection
        /// albumId must not be an empty string
        /// needs error checking
        /// </summary>
        /// <param name="albumId">string</param>
        /// <returns>Album</returns>
        public static Album getAlbum(string albumId)
        {
            Album theAlbum = new Album();
            try
            {
                using (var context = new artistEntities())
                {
                    theAlbum = context.Albums.Where(i => i.album_id == albumId).First();
                }
            }
            catch (Exception)
            {

                throw new IdentityMustExist(); ;
            }

            return theAlbum;
        }
    }
    /// <summary>
    /// General exception to throw when unable to change album name
    /// includes default error message
    /// </summary>
    public class UnableToEditAlbum : ApplicationException
    {
        public UnableToEditAlbum(string msg = "Unable to edit Album Name, please try again later.")
            : base(msg)
        {
        }
    }

    /// <summary>
    /// General exception to throw when unable to add a record
    /// includes default error message
    /// </summary>
    public class UnableToAddObject : ApplicationException
    {
        public UnableToAddObject(string msg = "Unable to add record")
            : base(msg)
        {
        }
    }

    /// <summary>
    /// ID insertion exception that includes a default error message
    /// </summary>
    public class IdentityMustBeUnique : ApplicationException
    {
        //call base constructor and pass a message
        //user can pass a new message or allow the default to be passed
        public IdentityMustBeUnique(string msg = "ID must be unique")
            : base(msg)
        {
        }

    }

    /// <summary>
    /// ID existence exception that includes a default error message
    /// </summary>
    public class IdentityMustExist : ApplicationException
    {
        //call base constructor and pass a message
        //user can pass a new message or allow the default to be passed
        public IdentityMustExist(string msg = "ID must exist")
            : base(msg)
        {
        }

    }

    /// <summary>
    /// ethrow this when empty strings are encountered
    /// </summary>
    public class FieldsMustNotBeBlank : ApplicationException
    {
        public FieldsMustNotBeBlank(string msg = "All text fields must be filled in.")
            : base(msg)
        {
        }
    }

}