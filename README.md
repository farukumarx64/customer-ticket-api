# Customer Ticket API

## Overview

The "Customer Ticket API" allows you to obtain a ticket ID by executing a script. This can be useful in scenarios where dynamic ticket creation is required, and a specific script generates the ticket ID.

## Endpoint

- **Endpoint URL:** `/api/ticket`
- **HTTP Method:** `GET`

## Request

No specific request parameters are required for this API. A simple HTTP GET request to the endpoint triggers the execution of the script.

**Example Request:**

```bash
curl -X GET https://your-api-domain/api/ticket
```

## Response

The API response provides a JSON object containing the generated ticket ID or an error message in case of failure.

**Success Response:**

```json
{
  "ticket": "unique_ticket_id"
}
```

- **`ticket` (string):** The generated ticket ID.

**Error Response:**

```json
{
  "error": "Error generating ticket",
  "ticket": ""
}
```

- **`error` (string):** A descriptive error message indicating the reason for the failure.
- **`ticket` (string):** An empty string as a placeholder for the ticket ID when an error occurs.

## Error Handling

In case of an error during script execution, the API responds with an HTTP status code of 500 and includes an error message in the response body.

## Implementation Details

- Language: C
- UUID Generation: The API utilizes C script to generate UUID-based ticket IDs.

## Notes

- Handle errors gracefully by checking the presence of the 'error' property in the API response.
- The generated ticket ID is provided in the 'ticket' property of the successful response.
