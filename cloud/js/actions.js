function getActions() {


    return {
        SMS:
            {
                text: "SMS",
                parameter:
                    [
                        {text: "Number", type: "tel"},
                        {text: "Message", type: "text"}
                    ],
                height: 180,
                background: "action-bg-blue"
            },
        get:
            {
                text: "HTTP-GET-Request",
                parameter:
                    [
                        {text: "URL", type: "text"}
                    ],
                height: 105,
                background: "action-bg-red"
            },
        mail:
            {
                text: "e-Mail",
                parameter:
                    [
                        {text: "Address", type: "email"},
                        {text: "Message", type: "text"}
                    ],
                height: 180,
                background: "action-bg-yellow"
            },
        push:
            {
                text: "Push-Notification",
                parameter:
                    [
                        {text: "ID", type: "text"}
                    ],
                height: 105,
                background: "action-bg-green"
            }

    };
}