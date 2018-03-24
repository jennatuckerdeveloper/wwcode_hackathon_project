const accountSid = 'ACc4772fd12e4a53426ae51b0308a74ff9'
const authToken = '189aadc721a07385b8d561181ded0fa7'
const client = require('twilio')(accountSid, authToken)
const express = require('express')
const app = express()

app.get('/', (req, res) => {

const notificationOpts = {
 toBinding: JSON.stringify({
   binding_type: 'sms',
   address: '+18573660630',
 }),
 body: 'Nick has a server working like a boss!',
};

client.notify
 .services('IS8b7d6977600f5d6e17219bf9e6057e86')
 .notifications.create(notificationOpts)
 .then(notification => res.send(notification.sid))
 .catch(error => res.send(error));

})
app.listen(3000, () => console.log('Example app listening on port 3000!'))
