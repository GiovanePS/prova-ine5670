import { Helmet } from 'react-helmet'
import { BarChart } from '@mui/x-charts/BarChart';

function App() {
  return (
    <>
    <Helmet>
      <title>Client IOT</title>
    </Helmet>
    <div className="w-ful bg-blue-500 p-4">
      <div className="bg-white min-h-screen mx-80 rounded">
        <h1 className="underline">Hello, world!</h1>
      <BarChart
        xAxis={[
          {
            id: 'barCategories',
            data: ['bar A', 'bar B', 'bar C'],
            scaleType: 'band',
          },
        ]}
        series={[
          {
            data: [2, 5, 3],
          },
        ]}
        width={500}
        height={300}
      />
    </div>
    </div>
    </>
  )
}

export default App
