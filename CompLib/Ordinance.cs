using System;
using System.Collections.Generic;
using System.Text;
using System.Data;

namespace CompLib
{
    /// <summary>
    /// Used to store information on procedures to run tests upon.
    /// </summary>
    [Serializable()]
    public class Ordinance : DataTable
    {
        #region Constructor

        /// <summary>
        /// Creates a new instance of the Engine class with the default schema.
        /// </summary>
        public Ordinance()
        {
            this.Columns.Add("Name", Type.GetType("System.String"));
            this.Columns.Add("Armor", Type.GetType("System.Double"));
            this.Columns.Add("Mass", Type.GetType("System.Double"));
            this.Columns.Add("Drain", Type.GetType("System.Double"));
            this.Columns.Add("Min Damage", Type.GetType("System.Double"));
            this.Columns.Add("Max Damage", Type.GetType("System.Double"));
            this.Columns.Add("vs Sheilds", Type.GetType("System.Double"));
            this.Columns.Add("vs Armor", Type.GetType("System.Double"));
            this.Columns.Add("Ammo", Type.GetType("System.Int32"));
            this.PrimaryKey = new DataColumn[] { this.Columns["Name"] };
        }

        #endregion

        #region Indexer

        /// <summary>
        /// Public indexer for setting or returning a specific row.
        /// </summary>
        /// <param name="index">Integer value of the row to modify.</param>
        /// <returns>DataRow object of the affected row.</returns>
        public DataRow this[int index]
        {
            get
            {
                return this.Rows[index];
            }
            set
            {
                this.Rows.RemoveAt(index);
                this.Rows.InsertAt(value, index);
            }
        }

        #endregion

        #region Methods

        /// <summary>
        /// Adds a new test to the table.
        /// </summary>
        /// <param name="name">String value representing the name of the test.</param>
        /// <param name="command">Byte value as the first character to send.</param>
        /// <param name="data">Byte value as an additional data character to send.</param>
        /// <param name="timeout">Int64 value representing the amount of time in ms to wait
        /// for the test to run before a timeout should occur.</param>
        public void AddOrdinance(string name, double armor, double mass, double drain, double minD, double maxD,
            double vsS, double vsA, Int32 ammo)
        {
            try
            {
                DataRow row = this.NewRow();
                row["Name"] = name;
                row["Armor"] = armor;
                row["Mass"] = mass;
                row["Drain"] = drain;
                row["Min Damage"] = minD;
                row["Max Damage"] = maxD;
                row["vs Sheilds"] = vsS;
                row["vs Armor"] = vsA;
                row["Ammo"] = ammo;
                this.Rows.Add(row);
            }
            catch (System.Data.DataException)
            {
                throw new Exception("The name of the test to add must be unique.");
            }
            catch (Exception err)
            {
                throw new Exception(String.Format("Error in {0}: {1}", err.TargetSite.ToString(), err.Message));
            }
        }

        /// <summary>
        /// Removes the specified test from the table.
        /// </summary>
        /// <param name="name">String value representing the name of the test to remove.</param>
        public void RemoveOrdinance(string name)
        {
            try
            {
                this.Rows.Remove(this.Rows.Find(name));
            }
            catch (Exception err)
            {
                throw new Exception(String.Format("Error in {0}: {1}", err.TargetSite.ToString(), err.Message));
            }
        }

        #endregion
    }
}