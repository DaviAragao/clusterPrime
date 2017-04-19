var firebase = require("firebase");

firebase.initializeApp({
	serviceAccount: "aguila-33d269a2bdb2.json",
	databaseURL: "https://aguila-82292.firebaseio.com"
});

var db = firebase.database();
var ref = db.ref("restricted_access/secret_document");
ref.once("value", function(snapshot) {
	  console.log(snapshot.val());
});
