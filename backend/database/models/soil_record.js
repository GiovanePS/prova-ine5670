import { DataTypes } from "sequelize";
import sequelize from '../sequelize_module'

const SoilMoisture_Record = sequelize.define('note', {
  id: {
    type: DataTypes.INTEGER,
    primaryKey: true,
    autoIncrement: true,
  },
  soil_moisture: {
    type: DataTypes.DOUBLE,
    allowNull: false,
  },
  timestamp: {
    type: DataTypes.DATE,
    allowNull: false,
  },
})

export default SoilMoisture_Record