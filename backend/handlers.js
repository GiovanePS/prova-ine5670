import HDT_Record from './database/models/hdt_record.js'
import Light_Record from './database/models/light_record.js'
import SoilMoisture_Record from './database/models/soil_record.js'

export const handlers = {
  dht: async (req, res) => {
    const { temperature, humidity } = req.body
    await HDT_Record.create({
      temperature: temperature,
      humidity: humidity,
      timestamp: Date.now()
    })
    res.status(200).send('Received')
  },

  yl: async (req, res) => {
    const { lightLevel } = req.body
    await Light_Record.create({
      light_level: lightLevel,
      timestamp: Date.now()
    })
    res.status(200).send('Received')
  },

  bh: async (req, res) => {
    const { soilMoisture } = req.body;
    await SoilMoisture_Record.create({
      soil_moisture: soilMoisture,
      timestamp: Date.now()
    })
    res.status(200).send('Received')
  }
}