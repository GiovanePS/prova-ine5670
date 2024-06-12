import express from 'express'
const bodyParser = require('body-parser')
const app = express()
import router from './routes'

app.use(bodyParser.json())

app.get('/ht', (req, res) => {
  res.send()
})

const port = process.env.PORT || 3000

app.use(router)

app.listen(port, () => {
  console.log(`Server is running on port ${port}.`)
})