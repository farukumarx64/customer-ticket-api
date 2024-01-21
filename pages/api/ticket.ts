import { execFile } from 'child_process';
import { NextApiRequest, NextApiResponse } from 'next';
import { join } from 'path';

interface ApiResponse {
  ticket: string;
  error?: string;
}

export default async function handler(
  req: NextApiRequest,
  res: NextApiResponse<ApiResponse>
) {
  try {
    const projectRoot = process.cwd();
    const scriptPath = join(projectRoot, 'pages', 'api', 'generate-ticket', 'generate-ticket');

    const { stdout } = await new Promise<{ stdout: string }>((resolve, reject) => {
      execFile(scriptPath, (err, stdout, stderr) => {
        if (err) {
          console.error(`Error executing child process: ${err}`);
          console.error(`Child process stderr: ${stderr}`);
          reject(err);
        } else {
          resolve({ stdout });
        }
      });
    });

    const ticket = stdout.trim();
    res.json({ ticket });
  } catch (error) {
    console.error(`Error generating ticket: ${error}`);
    res.status(500).json({ error: 'Error generating ticket', ticket: '' });
  }
}
