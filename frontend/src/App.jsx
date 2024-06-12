import { Helmet } from 'react-helmet'
import { LineChart } from '@mui/x-charts/LineChart';

function App() {
  const timeLabels = ['6 AM', '9 AM', '12 PM', '3 PM', '6 PM', '9 PM'];
  const temperatureData = [18, 22, 26, 28, 24, 20];
  const humidityData = [85, 80, 70, 60, 65, 75];
  const luminosityData = [200, 500, 800, 1000, 600, 300];
  const soilMoistureData = [30, 35, 40, 45, 38, 33];
  
  return (
    <>
    <Helmet>
      <title>Client IOT</title>
      <link rel="shortcut icon" href="icon.png" type="image/x-icon" />
    </Helmet>
    <div className="w-ful bg-blue-500 p-4">
      <h1 className='text-2xl'>12/06/2024</h1>
      <div className="flex flex-col justify-center items-center bg-white min-h-screen mx-80 rounded">
        <h1 className="text-4xl mt-8 mb-4">Temperature throughout the day</h1>
        <LineChart
          xAxis={[
            {
              id: 'timeCategories',
              data: timeLabels,
              scaleType: 'band',
            },
          ]}
          series={[
            {
              data: temperatureData,
              label: 'Temperature (°C)',
            },
          ]}
          width={600}
          height={400}
        />
        <h1 className="self-center text-4xl mt-8 mb-2">Humidity throughout the day</h1>
        <LineChart
          xAxis={[
            {
              id: 'timeCategories',
              data: timeLabels,
              scaleType: 'band',
            },
          ]}
          series={[
            {
              data: humidityData,
              label: 'Humidity (%)',
              color: '#fdb462'
            },
          ]}
          width={600}
          height={400}
        />
        <h2 className="self-center text-4xl mt-8 mb-2">Luminosity throughout the day</h2>
        <LineChart
          xAxis={[
            {
              id: 'timeCategories',
              data: timeLabels,
              scaleType: 'band',
            },
          ]}
          series={[
            {
              data: luminosityData,
              label: 'Luminosity (lx)',
              color: '#4e79a7'
            },
          ]}
          width={600}
          height={400}
        />
        <h2 className="self-center text-4xl mt-8 mb-2">Soil Moisture throughout the day</h2>
        <LineChart
          xAxis={[
            {
              id: 'timeCategories',
              data: timeLabels,
              scaleType: 'band',
            },
          ]}
          series={[
            {
              data: soilMoistureData,
              label: 'Soil Moisture (%)',
              color: '#9c755f'
            },
          ]}
          width={600}
          height={400}
        />
    </div>
    </div>
    </>
  )
}

export default App
