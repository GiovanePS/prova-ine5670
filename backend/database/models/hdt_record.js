import { DataTypes } from "sequelize";
import sequelize from '../sequelize_module'

const HDT_Record = sequelize.define('note', {
  id: {
    type: DataTypes.INTEGER,
    primaryKey: true,
    autoIncrement: true,
  },
  temperature: {
    type: DataTypes.DOUBLE,
    allowNull: false,
  },
  humidity: {
    type: DataTypes.DOUBLE,
    allowNull: false,
  },
  timestamp: {
    type: DataTypes.DATE,
    allowNull: false,
  },
})

export default HDT_Record