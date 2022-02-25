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
    public class ShipInfo : DataTable
    {
        #region Constructor

        /// <summary>
        /// Creates a new instance of the Engine class with the default schema.
        /// </summary>
        public ShipInfo()
        {
            this.Columns.Add("Name", Type.GetType("System.String"));
            this.Columns.Add("Chassis", Type.GetType("System.Int32"));
            this.Columns.Add("Mass", Type.GetType("System.Double"));
            this.Columns.Add("Reactor Overload", Type.GetType("System.Int32"));
            this.Columns.Add("Engine Overload", Type.GetType("System.Int32"));
            this.Columns.Add("Weapon Overload", Type.GetType("System.Int32"));
            this.Columns.Add("Capacitor Overload", Type.GetType("System.Int32"));
            this.Columns.Add("Loaded Reactor", Type.GetType("System.String"));
            this.Columns.Add("Loaded Engine", Type.GetType("System.String"));
            this.Columns.Add("Loaded Booster", Type.GetType("System.String"));
            this.Columns.Add("Loaded Sheild", Type.GetType("System.String"));
            this.Columns.Add("Loaded Front Armor", Type.GetType("System.String"));
            this.Columns.Add("Loaded Rear Armor", Type.GetType("System.String"));
            this.Columns.Add("Loaded Droid", Type.GetType("System.String"));
            this.Columns.Add("Loaded Capacitor", Type.GetType("System.String"));
            this.Columns.Add("Loaded Weapon 1", Type.GetType("System.String"));
            this.Columns.Add("Loaded Weapon 2", Type.GetType("System.String"));
            this.Columns.Add("Loaded Weapon 3", Type.GetType("System.String"));
            this.Columns.Add("Loaded Weapon 4", Type.GetType("System.String"));
            this.Columns.Add("Loaded Ordinance 1", Type.GetType("System.String"));
            this.Columns.Add("Loaded Ordinance 2", Type.GetType("System.String"));
            this.Columns.Add("Loaded Ordinance 3", Type.GetType("System.String"));
            this.Columns.Add("Loaded Chaff", Type.GetType("System.String")); 
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
        public void AddShip(string name, Int32 chassis, double mass, Int32 reactoroverload,
            Int32 engineoverload, Int32 weaponoverload, Int32 capacitoroverload, string loadedreactor,
            string loadedengine, string loadedbooster, string loadedsheild, string loadedfrontarmor,
            string loadedreararmor, string loadeddroid, string loadedcapacitor, string loadedweapon1,
            string loadedweapon2, string loadedweapon3, string loadedweapon4, string loadedordinance1,
            string loadedordinance2, string loadedordinance3, string loadedchaff)
        {
            try
            {
                DataRow row = this.NewRow();
                row["Name"] = name;
                row["Chassis"] = chassis;
                row["Mass"] = mass;
                row["Reactor Overload"] = reactoroverload;
                row["Engine Overload"] = engineoverload;
                row["Weapon Overload"] = weaponoverload;
                row["Capacitor Overload"] = capacitoroverload;
                row["Loaded Reactor"] = loadedreactor;
                row["Loaded Engine"] = loadedengine;
                row["Loaded Booster"] = loadedbooster;
                row["Loaded Sheild"] = loadedsheild;
                row["Loaded Front Armor"] = loadedfrontarmor;
                row["Loaded Rear Armor"] = loadedreararmor;
                row["Loaded Droid"] = loadeddroid;
                row["Loaded Capacitor"] = loadedcapacitor;
                row["Loaded Weapon 1"] = loadedweapon1;
                row["Loaded Weapon 2"] = loadedweapon2;
                row["Loaded Weapon 3"] = loadedweapon3;
                row["Loaded Weapon 4"] = loadedweapon4;
                row["Loaded Ordinance 1"] = loadedordinance1;
                row["Loaded Ordinance 2"] = loadedordinance2;
                row["Loaded Ordinance 3"] = loadedordinance3;
                row["Loaded Chaff"] = loadedchaff;
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
        public void RemoveShip(string name)
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