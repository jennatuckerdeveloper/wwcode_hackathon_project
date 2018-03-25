const accountSid = 'ACc4772fd12e4a53426ae51b0308a74ff9'
const authToken = '189aadc721a07385b8d561181ded0fa7'
const client = require('twilio')(accountSid, authToken)
const express = require('express')
const app = express()

let number = '+18573660630'
let sent = false

app.get('/notify/', (req, res) => {

if (sent === true) {
	res.send("Not going to spam")
	return
}

if (req.query.number != undefined) {
	number = '+1'+req.query.number
}
console.log(number)
const notificationOpts = {
 toBinding: JSON.stringify({
   binding_type: 'sms',
   address: number,
 }),
 body: 'Something smells a bit ripe...',
};

sent = true

client.notify
 .services('IS8b7d6977600f5d6e17219bf9e6057e86')
 .notifications.create(notificationOpts)
 .then(notification => res.send(notification.sid))
 .catch(error => res.send(error))

})

app.get('/change/', (req, res) => {
	if(req.query.number == undefined){
		res.send("'number' must be included")
		return
	}
	number = '+1' + req.query.number
	res.send('New number set')
	sent = false
})
app.listen(3000, () => console.log('App listening on port 3000'))
