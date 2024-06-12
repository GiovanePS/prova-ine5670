import express from 'express'
import { handlers } from './handlers.js'

const router = express.Router()

// DHT11
router.post('/ht', handlers.dht)

// YL-69
router.post('/soil', handlers.yl)

// BH1750
router.post('/light', handlers.bh)

export default router