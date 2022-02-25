using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;
using System.Xml.Serialization;
using System.IO;
using System.Data;
using System.Text.RegularExpressions;

namespace CompLib
{
    /// <summary>
    /// Contains static methods for reading and writing test configuration files.
    /// </summary>
    public class XMLUtilities
    {
        #region Methods

        /// <summary>
        /// Creates a new Ship Info file at the specified filename with the passed in data.
        /// </summary>
        /// <param name="filename">String value representing the location of which to save the file.</param>
        /// <param name="pilotname">String value representing the name of the pilot.</param>
        /// <param name="shipInfos">table array of the various loaded component types</param>
        public static void CreateShipInfoFile(string filename, string pilotname, ShipInfo[] shipInfos)
        {
            try
            {
                DataSet newShipInfoData = new DataSet(pilotname);

                if (shipInfos != null)
                {
                    foreach (ShipInfo s in shipInfos)
                    {
                        newShipInfoData.Tables.Add(s);
                    }
                }
                newShipInfoData.WriteXml(filename, XmlWriteMode.WriteSchema);

            }
            catch (Exception err)
            {
                throw new Exception(String.Format("Error in {0}: {1}", err.TargetSite.ToString(), err.Message));
            }
        }

        /// <summary>
        /// Creates a new configuration file at the specified filename with the passed in data.
        /// </summary>
        /// <param name="filename">String value representing the location of which to save the file.</param>
        /// <param name="pilotname">String value representing the name of the pilot.</param>
        /// <param name="*component*">table array of the various component types</param>
        public static void CreateCompFile(string filename, string pilotname, Reactor[] reactors, Engine[] engines,
            Booster[] boosters, Sheild[] sheilds, Armor[] armors, Droid[] droids, Capacitor[] capacitors,
            Ordinance[] ordinances, Weapon[] weapons, Chaff[] chaffs)
        {
            try
            {
                DataSet newTestData = new DataSet(pilotname);

                if (reactors != null)
                {
                    foreach (Reactor r in reactors)
                    {
                        newTestData.Tables.Add(r);
                    }
                }
                if (engines != null)
                {
                    foreach (Engine e in engines)
                    {
                        newTestData.Tables.Add(e);
                    }
                }
                if (boosters != null)
                {
                    foreach (Booster b in boosters)
                    {
                        newTestData.Tables.Add(b);
                    }
                }
                if (sheilds != null)
                {
                    foreach (Sheild s in sheilds)
                    {
                        newTestData.Tables.Add(s);
                    }
                }
                if (armors != null)
                {
                    foreach (Armor a in armors)
                    {
                        newTestData.Tables.Add(a);
                    }
                }
                if (droids != null)
                {
                    foreach (Droid d in droids)
                    {
                        newTestData.Tables.Add(d);
                    }
                }
                if (capacitors != null)
                {
                    foreach (Capacitor c in capacitors)
                    {
                        newTestData.Tables.Add(c);
                    }
                }
                if (ordinances != null)
                {
                    foreach (Ordinance o in ordinances)
                    {
                        newTestData.Tables.Add(o);
                    }
                }
                if (weapons != null)
                {
                    foreach (Weapon w in weapons)
                    {
                        newTestData.Tables.Add(w);
                    }
                }
                if (chaffs != null)
                {
                    foreach (Chaff m in chaffs)
                    {
                        newTestData.Tables.Add(m);
                    }
                }
                newTestData.WriteXml(filename, XmlWriteMode.WriteSchema);
                
            }
            catch (Exception err)
            {
                throw new Exception(String.Format("Error in {0}: {1}", err.TargetSite.ToString(), err.Message));
            }
        }

        /// <summary>
        /// Opens a configuration file a retrieves the data into referenced arrays.
        /// </summary>
        /// <param name="filename">String value as the path to the file to open.</param>
        /// <param name="shipInfos">Array to return data to.</param>
        /// <returns>String value representing the pilot name.</returns>
        public static string OpenShipInfoFile(string filename, ref ShipInfo[] shipInfos)
        {
            try
            {
                DataSet openShipInfoFileData = new DataSet();
                List<ShipInfo> tempShipInfo = new List<ShipInfo>();

                openShipInfoFileData.ReadXml(filename, XmlReadMode.ReadSchema);

                foreach (DataTable t in openShipInfoFileData.Tables)
                {
                    string tempTableName;
                    int tempTableNameIndex;

                    tempTableNameIndex = t.TableName.IndexOf('_');

                    tempTableName = t.TableName.Substring(0, tempTableNameIndex);

                    switch (tempTableName)
                    {
                        case "Ship":
                            ShipInfo newShipInfo = new ShipInfo();
                            newShipInfo.Merge(t);
                            newShipInfo.TableName = t.TableName;
                            tempShipInfo.Add(newShipInfo);
                            break;
                    }
                }

                shipInfos = tempShipInfo.ToArray();

                return openShipInfoFileData.DataSetName;
            }
            catch (Exception err)
            {
                throw new Exception(String.Format("Error in {0}: {1}", err.TargetSite.ToString(), err.Message));
            }
        }

        /// <summary>
        /// Opens a configuration file a retrieves the data into referenced arrays.
        /// </summary>
        /// <param name="filename">String value as the path to the file to open.</param>
        /// <param name="*component*">Array to return data to.</param>
        /// <returns>String value representing the pilot name.</returns>
        public static string OpenCompFile(string filename, ref Reactor[] reactors, ref Engine[] engines,
            ref Booster[] boosters, ref Sheild[] sheilds, ref Armor[] armors, ref Droid[] droids, ref Capacitor[] capacitors,
            ref Ordinance[] ordinances, ref Weapon[] weapons, ref Chaff[] chaffs)
        {
            try
            {
                DataSet openCompFileData = new DataSet();
                List<Reactor> tempReactor = new List<Reactor>();
                List<Engine> tempEngine = new List<Engine>();
                List<Booster> tempBooster = new List<Booster>();
                List<Sheild> tempSheild = new List<Sheild>();
                List<Armor> tempArmor = new List<Armor>();
                List<Droid> tempDroid = new List<Droid>();
                List<Capacitor> tempCapacitor = new List<Capacitor>();
                List<Weapon> tempWeapon = new List<Weapon>();
                List<Ordinance> tempOrdinance = new List<Ordinance>();
                List<Chaff> tempChaff = new List<Chaff>();

                openCompFileData.ReadXml(filename, XmlReadMode.ReadSchema);

                foreach (DataTable t in openCompFileData.Tables)
                {
                    string tempTableName;
                    int tempTableNameIndex;

                    tempTableNameIndex = t.TableName.IndexOf('_');

                    tempTableName = t.TableName.Substring(0, tempTableNameIndex);

                    switch (tempTableName)
                    {
                        case "Armor":
                            Armor newArmor = new Armor();
                            newArmor.Merge(t);
                            newArmor.TableName = t.TableName;
                            tempArmor.Add(newArmor);
                            break;
                        case "Booster":
                            Booster newBooster = new Booster();
                            newBooster.Merge(t);
                            newBooster.TableName = t.TableName;
                            tempBooster.Add(newBooster);
                            break;
                        case "Capacitor":
                            Capacitor newCapacitor = new Capacitor();
                            newCapacitor.Merge(t);
                            newCapacitor.TableName = t.TableName;
                            tempCapacitor.Add(newCapacitor);
                            break;
                        case "Chaff":
                            Chaff newChaff = new Chaff();
                            newChaff.Merge(t);
                            newChaff.TableName = t.TableName;
                            tempChaff.Add(newChaff);
                            break;
                        case "Weapon":
                            Weapon newWeapon = new Weapon();
                            newWeapon.Merge(t);
                            newWeapon.TableName = t.TableName;
                            tempWeapon.Add(newWeapon);
                            break;
                        case "Droid":
                            Droid newDroid = new Droid();
                            newDroid.Merge(t);
                            newDroid.TableName = t.TableName;
                            tempDroid.Add(newDroid);
                            break;
                        case "Engine":
                            Engine newEngine = new Engine();
                            newEngine.Merge(t);
                            newEngine.TableName = t.TableName;
                            tempEngine.Add(newEngine);
                            break;
                        case "Ordinance":
                            Ordinance newOrdinance = new Ordinance();
                            newOrdinance.Merge(t);
                            newOrdinance.TableName = t.TableName;
                            tempOrdinance.Add(newOrdinance);
                            break;
                        case "Reactor":
                            Reactor newReactor = new Reactor();
                            newReactor.Merge(t);
                            newReactor.TableName = t.TableName;
                            tempReactor.Add(newReactor);
                            break;
                        case "Sheild":
                            Sheild newSheild = new Sheild();
                            newSheild.Merge(t);
                            newSheild.TableName = t.TableName;
                            tempSheild.Add(newSheild);
                            break;
                    }
                }

                reactors = tempReactor.ToArray();
                engines = tempEngine.ToArray();
                boosters = tempBooster.ToArray();
                sheilds = tempSheild.ToArray();
                armors = tempArmor.ToArray();
                droids = tempDroid.ToArray();
                capacitors = tempCapacitor.ToArray();
                ordinances = tempOrdinance.ToArray();
                weapons = tempWeapon.ToArray();
                chaffs = tempChaff.ToArray();

                return openCompFileData.DataSetName;
            }
            catch (Exception err)
            {
                throw new Exception(String.Format("Error in {0}: {1}", err.TargetSite.ToString(), err.Message));
            }
        }

        /// <summary>
        /// Reads from an existing configuration file and loads the passed in tables with information
        /// contained in the file.
        /// </summary>
        /// <param name="filename">String value representing the path of the file to open.</param>
        /// <param name="*component*Table">String value representing the name of the componet table to return.</param>
        /// <param name="ref*component*">Component table to return.</param>
        /// <returns>String value representing the root node of the XML file which should be the pilot name.</returns>
        public static string RetrieveComp(string filename, string reactorTable, string engineTable, string boosterTable,
            string sheildTable, string armorTable, string droidTable, string capacitorTable, string ordinanceTable,
            string weaponTable, string chaffTable, ref Reactor refreactors, ref Engine refengines, ref Booster refboosters, 
            ref Sheild refsheilds, ref Armor refarmors, ref Droid refdroids, ref Capacitor refcapacitors, 
            ref Ordinance refordinances, ref Weapon refweapons, ref Chaff refchaffs)
        {
            try
            {
                DataSet existingData = new DataSet();
                if (File.Exists(filename))
                {
                    existingData.ReadXml(filename, XmlReadMode.ReadSchema);
                    refreactors.Merge(existingData.Tables[reactorTable], false,
                                            MissingSchemaAction.AddWithKey);
                    refengines.Merge(existingData.Tables[engineTable], false,
                                            MissingSchemaAction.AddWithKey);
                    refboosters.Merge(existingData.Tables[boosterTable], false,
                                            MissingSchemaAction.AddWithKey);
                    refsheilds.Merge(existingData.Tables[sheildTable], false,
                                            MissingSchemaAction.AddWithKey);
                    refarmors.Merge(existingData.Tables[armorTable], false,
                                            MissingSchemaAction.AddWithKey);
                    refdroids.Merge(existingData.Tables[droidTable], false,
                                            MissingSchemaAction.AddWithKey);
                    refcapacitors.Merge(existingData.Tables[capacitorTable], false,
                                            MissingSchemaAction.AddWithKey);
                    refordinances.Merge(existingData.Tables[ordinanceTable], false,
                                            MissingSchemaAction.AddWithKey);
                    refweapons.Merge(existingData.Tables[weaponTable], false,
                                            MissingSchemaAction.AddWithKey);
                    refchaffs.Merge(existingData.Tables[chaffTable], false,
                                            MissingSchemaAction.AddWithKey);
                    return existingData.DataSetName;
                }
                else
                {
                    throw new Exception("Configuration file could not be found.");
                }
            }
            catch (Exception err)
            {
                throw new Exception(String.Format("Error in {0}: {1}", err.TargetSite.ToString(), err.Message));
            }
        }

        /// <summary>
        /// Returns the Pilot name out of a configuration file.
        /// </summary>
        /// <param name="filename">String value of the file to read.</param>
        /// <returns>String value of the Pilot name.</returns>
        public static string PilotName(string filename)
        {
            try
            {
                DataSet config = new DataSet();
                if (File.Exists(filename))
                {
                    config.ReadXml(filename, XmlReadMode.ReadSchema);
                    return config.DataSetName;
                }
                else
                {
                    throw new Exception("Configuration file could not be found.");
                }
            }
            catch (Exception err)
            {
                throw new Exception(String.Format("Error in {0}: {1}", err.TargetSite.ToString(), err.Message));
            }
        }

        /// <summary>
        /// Returns an array of the part numbers contained in the file.
        /// </summary>
        /// <param name="filename">String value of the path of the file to read.</param>
        /// <returns>String array representing the part numbers each test is to be used with.</returns>
        public static string[] TestNames(string filename)
        {
            try
            {
                DataSet config = new DataSet();
                List<string> results = new List<string>();
                if (File.Exists(filename))
                {
                    config.ReadXml(filename, XmlReadMode.ReadSchema);
                    foreach (DataTable t in config.Tables)
                    {
                        if (Regex.IsMatch(t.TableName, "procedures_.+"))
                        {
                            results.Add(t.TableName.Substring(11));
                        }
                    }
                    return results.ToArray();
                }
                else
                {
                    throw new Exception("Configuration file could not be found.");
                }
            }
            catch (Exception err)
            {
                throw new Exception(String.Format("Error in {0}: {1}", err.TargetSite.ToString(), err.Message));
            }
        }

        #endregion
    }
}
