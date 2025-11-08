#simulated data : System diagnostics

def simulate_diagnostic_data(self):
    return {
            'battery' : random.randint(20,100),
            'motors' : random.choice(['OK','WARNING','ERROR']),
            'sensors' : random.choice(['OK','CALIBRATION','ERROR']),
            'temperature' : random.uniform(20,0,45.0)  .
            }
